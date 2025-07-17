# GStreamer Pipeline DOT Generator

This project shows how to generate a `.dot` file for a GStreamer pipeline and visualize it using Graphviz. It helps you inspect and debug GStreamer pipeline structures.

## 🔄 How it Works

1. Create a GStreamer pipeline in C.
2. Set the `GST_DEBUG_DUMP_DOT_DIR` environment variable.
3. Run the application.
4. GStreamer generates a `.dot` file representing the pipeline.
5. Convert the `.dot` file to a `.png` using Graphviz (`dot -Tpng`).

## 🛠 Requirements

- GStreamer (with `gst-launch-1.0`)
- Graphviz (`dot` command)
- GCC

## 🚀 How to Run

```bash
export GST_DEBUG_DUMP_DOT_DIR=./
./main
dot -Tpng pipeline.dot -o pipeline.png
