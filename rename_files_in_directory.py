import os

# This replaces all underscores with hyphens in any non-hidden file in the current directory
# [os.rename(f, f.replace('_', '-')) for f in os.listdir('.') if not f.startswith('.')]

# This replaces all 'txt' with 'ino' in any non-hidden file in the current directory
[os.rename(f, f.replace('txt', 'ino')) for f in os.listdir('.') if not f.startswith('.')]
