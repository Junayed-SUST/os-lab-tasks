#!/bin/bash

# Create files
echo "Creating files..."
touch file1.txt file2.txt
echo "Hello World" > file1.txt
echo "Created file1.txt and file2.txt"

# Copy file
echo "Copying file1.txt to file1_copy.txt..."
cp file1.txt file1_copy.txt

# Move file
echo "Moving file2.txt to moved_file.txt..."
mv file2.txt moved_file.txt

# Delete files
echo "Deleting files..."
rm file1.txt file1_copy.txt moved_file.txt
echo "Files deleted"

# Verify operations
echo "Current directory contents:"
ls -l
