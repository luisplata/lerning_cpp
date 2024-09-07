import os
import re

def process_file(file_path):
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            file_content = file.read()
            pattern = re.compile(r'public\s+ISystem')
            if pattern.search(file_content):
                print(f"File: {file_path}")
                print(f"Content:\n{file_content}\n")
    except Exception as e:
        print(f"Error reading file {file_path}: {e}")

def traverse_directory(directory_path):
    for root, _, files in os.walk(directory_path):
        for file in files:
            if file.endswith('.h') or file.endswith('.cpp'):
                file_path = os.path.join(root, file)
                process_file(file_path)

if __name__ == "__main__":
    directory_path = input("Enter directory path: ")
    traverse_directory(directory_path)