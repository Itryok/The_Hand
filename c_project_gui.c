#include <ctype.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "c_project_core.h"

// Make them global

GtkWidget* window;
GtkBuilder* builder;
GtkAdjustment* gripper_angle_adjustment;
GtkAdjustment* wrist_pitch_angle_adjustment;
GtkAdjustment* wrist_roll_angle_adjustment;
GtkAdjustment* elbow_angle_adjustment;
GtkAdjustment* shoulder_angle_adjustment;
GtkAdjustment* waist_angle_adjustment;

void quit_now(){
    cleanup();
    gtk_main_quit();
}

int main(int argc, char* argv[])
{

    gtk_init(&argc, &argv); // init Gtk

    if (init() < 0)
        return EXIT_FAILURE;

    //---------------------------------------------------------------------
    // establish contact with xml code used to adjust widget settings
    //---------------------------------------------------------------------

    builder = gtk_builder_new_from_file("project_gui.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

    g_signal_connect(window, "destroy", G_CALLBACK(quit_now), NULL);

    gtk_builder_connect_signals(builder, NULL);

    gripper_angle_adjustment = GTK_ADJUSTMENT(
        gtk_builder_get_object(builder, "gripper_angle_adjustment"));
    wrist_pitch_angle_adjustment = GTK_ADJUSTMENT(
        gtk_builder_get_object(builder, "wrist_pitch_angle_adjustment"));
    wrist_roll_angle_adjustment = GTK_ADJUSTMENT(
        gtk_builder_get_object(builder, "wrist_roll_angle_adjustment"));
    elbow_angle_adjustment = GTK_ADJUSTMENT(gtk_builder_get_object(builder, "elbow_angle_adjustment"));
    shoulder_angle_adjustment = GTK_ADJUSTMENT(
        gtk_builder_get_object(builder, "shoulder_angle_adjustment"));
    waist_angle_adjustment = GTK_ADJUSTMENT(gtk_builder_get_object(builder, "waist_angle_adjustment"));

    gtk_widget_show(window);

    gtk_main();

    return EXIT_SUCCESS;
}

void set_gripper_angle(GtkAdjustment* adj, gpointer data)
{
    float value = (float)gtk_adjustment_get_value(adj);
    set_servo_position(servos[0], (unsigned int)value);
}

void set_wrist_pitch_angle(GtkAdjustment* adj, gpointer data)
{
    float value = (float)gtk_adjustment_get_value(adj);
    set_servo_position(servos[1], (unsigned int)value);
}

void set_wrist_roll_angle(GtkAdjustment* adj, gpointer data)
{
    float value = (float)gtk_adjustment_get_value(adj);
    set_servo_position(servos[2], (unsigned int)value);
}

void set_elbow_angle(GtkAdjustment* adj, gpointer data)
{
    float value = (float)gtk_adjustment_get_value(adj);
    set_servo_position(servos[3], (unsigned int)value);
}

void set_shoulder_angle(GtkAdjustment* adj, gpointer data)
{
    float value = (float)gtk_adjustment_get_value(adj);
    set_servo_position(servos[4], (unsigned int)value);
}

void set_waist_angle(GtkAdjustment* adj, gpointer data)
{
    float value = (float)gtk_adjustment_get_value(adj);
    set_servo_position(servos[5], (unsigned int)value);
}

