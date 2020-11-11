# Qt-SchoolPlanner

build&run:
mkdir build; cd build;
qmake ../SchoolPlanner.pro
make
./SchoolPlanner

Rules:
- when start a program there is a need to load .json file with data (example data can be found in data.json) 
File -> Open.. 
The user is now asked to select a file.
- if there is any error in data - there are no rooms, classes, teachers or groups, there should be an error.
Slots are numbered form 0 to 9.
- if there is missing attribute in activites (gorup, class or teacher) the program asks user if such activity should be ommited - if no, it is saved as program data anyway.
- user can edit (add/remove) lists: rooms, groups, classes, teachers (Edit -> (select list))
When removing entry there is a warning displayed that is will cause removal of all activities connected to selected data. User can select to proceed or cancel.
- user can edit activites by double clicking on any entry on the table. 
There should be displayed an edit form which also contains more details about selected entry.
If selected entry already have any data assigned there is a button "unassign" which deletes data form this entry.
When edited/added activity conflicts with other activites (selected group/teacher has classes at the same time in different room) 
program displays warning - conflicting activites will be removed, and asks user to accept or cancel.

To delete all data: File -> New
User will be asked to save current changes.

To save data to the same file from where data were read: File -> Save
If there is no such file, the user will be asked to select new file.

To save data in a new file: File -> Save as.. 


