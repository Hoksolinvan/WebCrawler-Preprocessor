**Project:** Preprocessing Pipeline for a Web Crawler

This project involves the development of a preprocessing pipeline for a web crawler aimed at enhancing the quality of indexed data for search tools. The pipeline consists of three key components:

**Text Cleaning:**

**Functionality:** Converts all uppercase letters to lowercase and removes punctuation from text files.
**Implementation:** Developed a C program (text-cleaner.c) that processes text character by character, ensuring only relevant text data is passed on to the next stage.


**Stop Word Removal:**

**Functionality:** Eliminates common stop words from the text to reduce noise and improve the quality of the data.
**Implementation:** Refactored an existing tool (stop-word-remover.c) to focus solely on the removal of stop words, ensuring a more streamlined and cohesive codebase.


**Stemming:**

**Functionality:** Reduces words to their base or root form, such as transforming "running" and "ran" to "run".
**Implementation:** Adapted an existing stemming program (stemmer.c) to integrate with the pipeline, modifying it to read from standard input and ensuring compatibility with the rest of the preprocessing tools.


**Features and Technologies**
Environment: Developed and tested on Linux machines.
Pipeline: Each program reads from standard input and writes to standard output, enabling seamless integration through Unix pipes.
