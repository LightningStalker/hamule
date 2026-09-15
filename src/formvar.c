/* Compile with $gcc -o formvar formvar.c -lform -lncurses && ./formvar
 * Fill-in form that passes numerical values to
 *  calculator programs, a simple UI
 *
 * Project Crew 2024 */

#include <stdlib.h>
#include <locale.h>
#include <form.h>
#include <string.h>

int
main()
{
    FIELD * field[5];
    FORM * my_form;
    int ch,
        t,
        numfields = 4;
    char fieldnames[8] = { "Field #:" };

    setlocale(LC_ALL, "");

    /* Initialize curses */
    initscr();
    cbreak();
    noecho();
    nonl();
    keypad(stdscr, TRUE);

    /* Initialize the fields */
    field[0] = new_field(1, 40,  4, 18, 0, 0);
    field[1] = new_field(1, 40,  6, 18, 0, 0);
    field[2] = new_field(1, 40,  8, 18, 0, 0);
    field[3] = new_field(1, 40, 10, 18, 0, 0);
    field[4] = NULL;

    /* Set field options */
    for (t = 0; t < numfields; t++)
    {
        set_field_back(field[t], A_UNDERLINE); /* Print a line for the option     */
        field_opts_off(field[t], O_AUTOSKIP);  /* Don't go to next field when this */
                                               /* Field is filled up      */
                                               /* Discard leading whitespace */
        set_field_pad(field[t], 0);            /* Pad fields with zeros */
        set_field_type(field[t], TYPE_NUMERIC, 13, -1e100, 1e100);
        /* Validate fields as floating point numbers */
    }

    /* Create the form and post it */
    my_form = new_form(field);
    post_form(my_form);
    refresh();

    for (t = 0; t < numfields; t++)
    {
        fieldnames[6] = t + 0x31;
        mvprintw(4 + t * 2, 2, "%s", fieldnames);
    }
    refresh();

    /* Get us to the first field */
    form_driver(my_form, REQ_END_LINE);

    /* Loop through to get user requests */
 userwait:
    while ( ( ch = getch() ) != KEY_F(1) ) // while key is not F1 loop through the other options.
    {
        switch ( ch )
        {
            case KEY_DOWN:
            case 9:
            case 10:
            case 13:
            case KEY_ENTER:
                /* Go to next field */
                form_driver(my_form, REQ_NEXT_FIELD);
                /* Go to the end of the present buffer */
                /* Leaves nicely at the last character */
                form_driver(my_form, REQ_END_LINE);
                break;
            case KEY_LEFT:
                /* Move left in field */
                form_driver(my_form, REQ_PREV_CHAR);
                break;
            case KEY_RIGHT:
                /* Move right in field */
                form_driver(my_form, REQ_NEXT_CHAR);
                break;
            case KEY_UP:
            case KEY_BTAB:
                /* Go to previous field */
                form_driver(my_form, REQ_PREV_FIELD);
                form_driver(my_form, REQ_END_LINE);
                break;
            case KEY_BACKSPACE:
                /* Go to previous field */
                form_driver(my_form, REQ_DEL_PREV);
                break;
            /* If this is a normal character, it gets */
            /* Printed                                */
            default:
                form_driver(my_form, ch);
                break;
        } /* switch */
    }

    char params[3][40];
    char * paramptr;
    int nulerr = 0;

    if (form_driver(my_form, REQ_NEXT_FIELD) == E_OK)  // put data in buffer
    {
        ;              // good keep going
    }
    else
    {
        goto userwait; // data invalid, go back
    }

    // Get user data...
    for (t = 0; t < numfields; t++)
    {
        paramptr = strtok(field_buffer(field[t], 0), " ");
        if (paramptr == NULL)
        {
            nulerr++;
        }
        else
        {
            strncpy(params[t], field_buffer(field[t], 0), 40);
            params[t][39] = '\0';
        }
    }

    /* Un post form and free the memory */
    unpost_form(my_form);
    free_form(my_form);
    free_field(field[0]);
    free_field(field[1]);
    free_field(field[2]);
    free_field(field[3]);

    endwin();

    printf("%s, %s, %s, %s\n", params[0], params[1], params[2], params[3]);

    if (nulerr > 0)
    {
        printf("%i fields were left blank so expect some problems.\n", nulerr);
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
} /* main */
