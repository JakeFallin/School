#include <gtk/gtk.h>
 #include <time.h>
 #include <stdlib.h>
static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  gtk_widget_destroy(widget);


}






  









// int
// main (int    argc,
//       char **argv)
// {

//   GtkWidget *window;
//   gtk_init(&argc, &argv);
//   window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
//   gtk_widget_set_size_request (window, 400, 400);
//   gtk_window_set_title (GTK_WINDOW (window), "Window");
//   gtk_window_set_default_size (GTK_WINDOW (window), 500, 500);
  
//   GtkWidget *box;

//   box = gtk_vbox_new (FALSE, 0);
//   gtk_container_add (GTK_CONTAINER (window)
//   // GtkWidget *button;
//   // button = gtk_button_new_with_label("Flip A Coin");
//   // g_signal_connect (button, "clicked",
//   //         G_CALLBACK (callbackf), (gpointer) "cool button");

//   // gtk_container_add (GTK_CONTAINER (window), button);





static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *button_box;
  GtkWidget *button_box2;
  GtkWidget *image;
  GtkWidget *label;

  srand(time(NULL));
  int r = rand() % 10;
  



  if(r > 4) {
    image = gtk_image_new_from_file("heads.jpg");
      label = gtk_label_new_with_mnemonic("Pongs");

  } else {
    image = gtk_image_new_from_file("tails.jpg");
          label = gtk_label_new_with_mnemonic("Pings");

  }

    gtk_container_add (GTK_CONTAINER (button_box2), image);

    gtk_container_add (GTK_CONTAINER (button_box2), label);
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 240);

  button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
    button_box2 = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);

  gtk_container_add (GTK_CONTAINER (window), button_box);

  button = gtk_button_new_with_label ("Hello World");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  gtk_container_add (GTK_CONTAINER (button_box), button);




// }
  gtk_widget_show_all (window);
  gtk_main();

}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}