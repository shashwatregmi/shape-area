# shape-area

Calculates the area and perimeter/circumfrence of various shapes by reading data from text files - by utilizing file streams and classes. The program opens the text file "files.txt" to read the names of the specific text files that contain data of the shapes. The names of the text files must be on different lines and in the same directory as the project.

Specific files (such as "shapes1.txt" - as listed on "files.txt") are opened by the program and the area/perimeter/circumfrence is calculated. 

Format recognized by the program is:

- Rectangle: r sidelength_1 sidelength_2
- Square: r sidelenght sidelength
- Triangle: t base height
- Circle: c radius

Please note that all other invalid inputs are just ignored/skipped by the program. Currently recognizes rectangles, squares, triangles and circles only, further shape functionality may updated later.



