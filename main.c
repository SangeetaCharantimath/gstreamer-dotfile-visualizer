#include <gst/gst.h>

int main(int argc, char *argv[]) {
    GstElement *pipeline;
    GError *error = NULL;

    // Initialize GStreamer
    gst_init(&argc, &argv);

    // Create pipeline using gst_parse_launch
    pipeline = gst_parse_launch("videotestsrc ! autovideosink", &error);

    if (!pipeline) {
        g_printerr("Failed to create pipeline: %s\n", error->message);
        g_clear_error(&error);
        return -1;
    }

    // Generate DOT file to visualize the pipeline
    GST_DEBUG_BIN_TO_DOT_FILE(GST_BIN(pipeline), GST_DEBUG_GRAPH_SHOW_ALL, "pipeline");

    // Set pipeline to PLAYING state for a short time
    gst_element_set_state(pipeline, GST_STATE_PLAYING);
    g_print("Pipeline running... (showing test video for 5 seconds)\n");
    g_usleep(5 * G_USEC_PER_SEC);

    // Stop the pipeline
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);
    g_print("Pipeline stopped. DOT file generated as 'pipeline.dot'.\n");

    return 0;
}
