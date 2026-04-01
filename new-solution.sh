#!/bin/bash

# Usage: ./new-solution.sh <topic> <language> <number> <problem-name>
# Example: ./new-solution.sh arrays-and-hashing cpp 001 two-sum

TOPIC=$1
LANG=$2
NUMBER=$3
NAME=$4

# Validate inputs
if [ -z "$TOPIC" ] || [ -z "$LANG" ] || [ -z "$NUMBER" ] || [ -z "$NAME" ]; then
    echo "Usage: ./new-solution.sh <topic> <language> <number> <problem-name>"
    echo "Example: ./new-solution.sh arrays-and-hashing cpp 001 two-sum"
    echo ""
    echo "Topics: arrays-and-hashing, two-pointers, sliding-window, stack,"
    echo "        binary-search, linked-list, trees, graphs, dynamic-programming,"
    echo "        heaps, backtracking, tries, greedy, bit-manipulation"
    echo ""
    echo "Languages: java, cpp"
    exit 1
fi

# Set file extension
if [ "$LANG" == "java" ]; then
    EXT="java"
elif [ "$LANG" == "cpp" ]; then
    EXT="cpp"
else
    echo "Error: Language must be 'java' or 'cpp'"
    exit 1
fi

# Create file path
FILE_PATH="${TOPIC}/${LANG}/${NUMBER}-${NAME}.${EXT}"

# Check if directory exists
if [ ! -d "${TOPIC}/${LANG}" ]; then
    echo "Error: Directory ${TOPIC}/${LANG}/ does not exist"
    exit 1
fi

# Check if file already exists
if [ -f "$FILE_PATH" ]; then
    echo "File already exists: $FILE_PATH"
    exit 1
fi

# Create file with header
cat > "$FILE_PATH" << EOF
// Problem: ${NAME} (LeetCode #${NUMBER})
// Link: https://leetcode.com/problems/${NAME}/
// Approach: TODO
// Time: O(?) | Space: O(?)

// Write your solution below

EOF

echo "Created: $FILE_PATH"
echo "Open it in your editor and paste your solution."