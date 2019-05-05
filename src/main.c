#include <gtk/gtk.h>
#include "uifunc.h"
gchar text_field[100];
gchar answer[20];
int mistake = 0;
int lenght = 0;
GtkWidget *field;

int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);

	GtkWidget *button_one, *button_two, *button_three, *button_four,
	    *button_five, *button_six, *button_seven, *button_eight,
	    *button_nine, *button_zero;
	GtkWidget *button_point, *button_leftBracket, *button_rightBracket,
	    *button_divide, *button_multiply, *button_plus, *button_minus,
	    *button_result, *button_allclear;
	button_one = gtk_button_new_with_label("1");  // num block
	g_signal_connect(G_OBJECT(button_one), "clicked",
			 G_CALLBACK(button_one_clicked), "1");
	button_two = gtk_button_new_with_label("2");
	g_signal_connect(G_OBJECT(button_two), "clicked",
			 G_CALLBACK(button_two_clicked), "2");
	button_three = gtk_button_new_with_label("3");
	g_signal_connect(G_OBJECT(button_three), "clicked",
			 G_CALLBACK(button_three_clicked), "3");
	button_four = gtk_button_new_with_label("4");
	g_signal_connect(G_OBJECT(button_four), "clicked",
			 G_CALLBACK(button_four_clicked), "4");
	button_five = gtk_button_new_with_label("5");
	g_signal_connect(G_OBJECT(button_five), "clicked",
			 G_CALLBACK(button_five_clicked), "5");
	button_six = gtk_button_new_with_label("6");
	g_signal_connect(G_OBJECT(button_six), "clicked",
			 G_CALLBACK(button_six_clicked), "6");
	button_seven = gtk_button_new_with_label("7");
	g_signal_connect(G_OBJECT(button_seven), "clicked",
			 G_CALLBACK(button_seven_clicked), "7");
	button_eight = gtk_button_new_with_label("8");
	g_signal_connect(G_OBJECT(button_eight), "clicked",
			 G_CALLBACK(button_eight_clicked), "8");
	button_nine = gtk_button_new_with_label("9");
	g_signal_connect(G_OBJECT(button_nine), "clicked",
			 G_CALLBACK(button_nine_clicked), "9");
	button_zero = gtk_button_new_with_label("0");
	g_signal_connect(G_OBJECT(button_zero), "clicked",
			 G_CALLBACK(button_zero_clicked), "0");

	button_divide = gtk_button_new_with_label("/");
	g_signal_connect(G_OBJECT(button_divide), "clicked",
			 G_CALLBACK(button_divide_clicked), "/");
	button_multiply = gtk_button_new_with_label("*");
	g_signal_connect(G_OBJECT(button_multiply), "clicked",
			 G_CALLBACK(button_multiply_clicked), "*");
	button_plus = gtk_button_new_with_label("+");
	g_signal_connect(G_OBJECT(button_plus), "clicked",
			 G_CALLBACK(button_plus_clicked), "+");
	button_minus = gtk_button_new_with_label("-");
	g_signal_connect(G_OBJECT(button_minus), "clicked",
			 G_CALLBACK(button_minus_clicked), "-");
	button_allclear = gtk_button_new_with_label("AC");
	g_signal_connect(G_OBJECT(button_allclear), "clicked",
			 G_CALLBACK(button_allclear_clicked), "AC");
	button_leftBracket = gtk_button_new_with_label("(");
	g_signal_connect(G_OBJECT(button_leftBracket), "clicked",
			 G_CALLBACK(button_leftBracket_clicked), "(");
	button_rightBracket = gtk_button_new_with_label(")");
	g_signal_connect(G_OBJECT(button_rightBracket), "clicked",
			 G_CALLBACK(button_rightBracket), ")");
	button_point = gtk_button_new_with_label(".");
	g_signal_connect(G_OBJECT(button_point), "clicked",
			 G_CALLBACK(button_point_clicked), ".");
	button_result = gtk_button_new_with_label("Вычислить");
	g_signal_connect(G_OBJECT(button_result), "clicked",
			 G_CALLBACK(button_result_clicked), "=");

	GtkWidget *window;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Калькулятор");
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 380);

	field = gtk_entry_new();

	GtkWidget *table;
	table = gtk_table_new(4, 6, FALSE);
	gtk_table_attach_defaults(GTK_TABLE(table), field, 0, 3, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(table), button_allclear, 3, 4, 0,
				  1);
	gtk_table_attach_defaults(GTK_TABLE(table), button_seven, 0, 1, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(table), button_eight, 1, 2, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(table), button_nine, 2, 3, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(table), button_plus, 3, 4, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(table), button_four, 0, 1, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE(table), button_five, 1, 2, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE(table), button_six, 2, 3, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE(table), button_minus, 3, 4, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE(table), button_one, 0, 1, 3, 4);
	gtk_table_attach_defaults(GTK_TABLE(table), button_two, 1, 2, 3, 4);
	gtk_table_attach_defaults(GTK_TABLE(table), button_three, 2, 3, 3, 4);
	gtk_table_attach_defaults(GTK_TABLE(table), button_divide, 3, 4, 3, 4);
	gtk_table_attach_defaults(GTK_TABLE(table), button_leftBracket, 0, 1, 4,
				  5);
	gtk_table_attach_defaults(GTK_TABLE(table), button_rightBracket, 1, 2,
				  4, 5);
	gtk_table_attach_defaults(GTK_TABLE(table), button_point, 2, 3, 4, 5);
	gtk_table_attach_defaults(GTK_TABLE(table), button_multiply, 3, 4, 4,
				  5);
	gtk_table_attach_defaults(GTK_TABLE(table), button_zero, 0, 1, 5, 6);
	gtk_table_attach_defaults(GTK_TABLE(table), button_result, 1, 4, 5, 6);

	gtk_container_add(GTK_CONTAINER(window), table);
	gtk_widget_show_all(window);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();

	return 0;
}
