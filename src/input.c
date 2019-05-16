#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "input.h"
#include<gtk/gtk.h>

extern int mistake;
extern int lenght;
int compare (char ch, char *list) //Сравнение символа со списком
{
    int i;
    for (i = 0; list[i] != '\0'; i++)
    {
        if (ch == list[i])
            return 1;
    }
    return 0;
}

void input(char** str, int* mistake, int* lenght) //Ввод примера
{
      GtkWidget *dialog, *window, *text;
dialog = gtk_dialog_new_with_buttons("Error",
                                             NULL,
                                             GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                             GTK_STOCK_OK,
                                             GTK_RESPONSE_ACCEPT,
                                             NULL);
    window = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
int i, j, open_brackets = 0;
 

    for (i = 0; (*str)[i] != '\n'; i++)
    {
        if (compare ((*str)[i], "()-+/*^s.0123456789"))
        {
            *lenght = *lenght + 1;
            if ((*str)[i] == '(') //Если скобка открывается
            {
                open_brackets++;
            }
            if ((*str)[i] == ')') //Если скобка закрывается
            {
                open_brackets--;
                if (open_brackets < 0) //Если закрытых скобок больше открытых
                {
                    
    text = gtk_label_new("Wrong input. Not found opened bracket before closed bracket.");

 gtk_container_add(GTK_CONTAINER(window), text); 
 gtk_widget_show(text);
     gtk_dialog_run(GTK_DIALOG(dialog));
gtk_widget_destroy(dialog);

                    *mistake = 1;
                    return ;
                }
            }
        }
        else
        {
        
    text = gtk_label_new("Wrong symbol.");

 gtk_container_add(GTK_CONTAINER(window), text); 
 gtk_widget_show(text);
     gtk_dialog_run(GTK_DIALOG(dialog));
gtk_widget_destroy(dialog); 

            *mistake = 1;
            return ;
        }
    }
    if (open_brackets) //Если открытых скобок больше закрытых
    {
       
    text = gtk_label_new("Wrong input. Too many opened brackets.");

 gtk_container_add(GTK_CONTAINER(window), text); 
     gtk_dialog_run(GTK_DIALOG(dialog));
gtk_widget_destroy(dialog);
 *mistake = 1;
        return ;
    }
    for (i = 0; (*str)[i] != '\0'; i++)
    {
        if (compare((*str)[i], "+/*^s") && (( (i == 0) || ((*str)[i + 1] =='\0') || ((*str)[i - 1] == '(') || ((*str)[i + 1] == ')') ) || ( (i > 0) && ((compare((*str)[i - 1], "+-/*^s")) || (compare((*str)[i + 1], "+-/*^s")))))) //Неправильное расположение знаков
        {
         
    
    text = gtk_label_new("Wrong input. Symbol placement error.");

 gtk_container_add(GTK_CONTAINER(window), text); 
 gtk_widget_show(text);
     gtk_dialog_run(GTK_DIALOG(dialog));
gtk_widget_destroy(dialog);  
            *mistake = 1;
            return ;
        }
        if (((*str)[i] == '.') && (( i - 1 < 0) || (compare((*str)[i + 1], "-+/*s") || compare((*str)[i - 1], "+-/*s") || ((*str)[i + 1] == '\0') || ((*str)[i - 1] == '\0'))))//Неправильное расположение точки WIP
        {
            
    text = gtk_label_new("Wrong input.");

 gtk_container_add(GTK_CONTAINER(window), text); 
 gtk_widget_show(text);
     gtk_dialog_run(GTK_DIALOG(dialog));
gtk_widget_destroy(dialog); 
        }
        if ((*str)[i] == '.')//Точка рядом со скобками
        {
            if (compare((*str)[i + 1], "()") || compare((*str)[i - 1], "()"))
            {

    text = gtk_label_new("Wrong input. Dot before or after bracket.");

 gtk_container_add(GTK_CONTAINER(window), text); 
 gtk_widget_show(text);
     gtk_dialog_run(GTK_DIALOG(dialog));
gtk_widget_destroy(dialog);                 
                *mistake = 1;
                return ;
            }
            for (j = i + 1; (*str)[j] != '\0'; j++)
            {
                if ((*str)[j] == '.')
                {

    text = gtk_label_new("Wrong input. Double dot.");

 gtk_container_add(GTK_CONTAINER(window), text); 
 gtk_widget_show(text);
     gtk_dialog_run(GTK_DIALOG(dialog));
gtk_widget_destroy(dialog);                     

                    *mistake = 1;
                    return ;
                }
            }
        }
        if (((*str)[i] == '(') && (i > 0))
        {
            if (compare((*str)[i - 1], "(+-/*^s") == 0)
            {

    text = gtk_label_new("Wrong input. Not found symbol before bracket.");

 gtk_container_add(GTK_CONTAINER(window), text); 
 gtk_widget_show(text);
     gtk_dialog_run(GTK_DIALOG(dialog));
gtk_widget_destroy(dialog);                 

                *mistake = 1;
                return ;
            }
            if ((*str)[i + 1] == ')')
            {
              
    text = gtk_label_new("Wrong input. Empty brackets.");

 gtk_container_add(GTK_CONTAINER(window), text); 
 gtk_widget_show(text);
     gtk_dialog_run(GTK_DIALOG(dialog));
gtk_widget_destroy(dialog); 

                *mistake = 1;
                return ;
            }
        }
        if (((*str)[i] == ')') && ((*str)[i + 1] != '\0'))
        {
            if (compare((*str)[i + 1], ")+-/*^s") == 0)
            {

    text = gtk_label_new("Wrong input. Not found symbol after bracket.");

 gtk_container_add(GTK_CONTAINER(window), text); 
 gtk_widget_show(text);
     gtk_dialog_run(GTK_DIALOG(dialog));
gtk_widget_destroy(dialog);                
                *mistake = 1;
                return ;
            }
        }
    }
}
