#include<string.h>
#include<gtk/gtk.h>
#include"func.h"
#include"input.h"

gchar answer[20];

void button_one_clicked(GtkWidget* widget, gpointer data) {
	strcat(text_field, (gchar*)data);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}
void button_two_clicked(GtkWidget* widget, gpointer data) {
	strcat(text_field, (gchar*)data);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}
void button_three_clicked(GtkWidget* widget, gpointer data)

{
	strcat(text_field, (gchar*)data);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}
void button_four_clicked(GtkWidget* widget, gpointer data)

{
	strcat(text_field, (gchar*)data);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}
void button_five_clicked(GtkWidget* widget, gpointer data)

{
	strcat(text_field, (gchar*)data);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}
void button_six_clicked(GtkWidget* widget, gpointer data)

{
	strcat(text_field, (gchar*)data);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}
void button_seven_clicked(GtkWidget* widget, gpointer data)

{
	strcat(text_field, (gchar*)data);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}
void button_eight_clicked(GtkWidget* widget, gpointer data)

{
	strcat(text_field, (gchar*)data);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}
void button_nine_clicked(GtkWidget* widget, gpointer data)

{
	strcat(text_field, (gchar*)data);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}
void button_zero_clicked(GtkWidget* widget, gpointer data)

{
	strcat(text_field, (gchar*)data);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}
void button_divide_clicked(GtkWidget* widget, gpointer data)

{
	strcat(text_field, (gchar*)data);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}
void button_multiply_clicked(GtkWidget* widget, gpointer data)

{
	strcat(text_field, (gchar*)data);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}
void button_plus_clicked(GtkWidget* widget, gpointer data)

{
	strcat(text_field, (gchar*)data);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}
void button_minus_clicked(GtkWidget* widget, gpointer data)

{
	strcat(text_field, (gchar*)data);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}
void button_allclear_clicked(GtkWidget* widget, gpointer data) {
	memset(text_field, 0, 100);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}

void button_leftBracket_clicked(GtkWidget* widget, gpointer data)

{
	strcat(text_field, (gchar*)data);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}
void button_rightBracket_clicked(GtkWidget* widget, gpointer data)

{
	strcat(text_field, (gchar*)data);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}
void button_point_clicked(GtkWidget* widget, gpointer data) {
	strcat(text_field, (gchar*)data);
	gtk_entry_set_text(GTK_ENTRY(field), text_field);
}
void button_result_clicked(GtkWidget* widget, gpointer data) {
	char* p = &text_field[0];
	input(&p, &mistake, &lenght);
	printf("%s,length %d, mistake%d\n", p, lenght, mistake);
	sprintf(answer, "%lf", Calculation(text_field, 0, lenght - 1));
	printf("%s\n", answer);
	gtk_entry_set_text(GTK_ENTRY(field), answer);
	lenght = 0;
}

