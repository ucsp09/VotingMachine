# Voting Machine
 This is a voting machine for 5 parties built using keil uvsion5 software and proteus 8 professional software by interfacing LM016L (LCD), LED-GREEN and SW-SPST-MOM (Switch) with AT89C51 (8051 microcontroller).
# Building
For ruuning the project
1. Install keil uvision5 and proteus 8 professional software on your pc.
2. Open keil uvision5 software and create a new project.
3. Copy the files present in lib folder to your workspace directory.
4. Now copy the votingmachine.c file present in test folder to the Sourcegroup folder in your project.
5. Generate the hex file by compiling and building votingmachine.c.
6. Now open the proteus project VotingMachine present in proteus folder using the proteus 8 professional software installed on your pc.
7. Now double click on AT89C51 and add the hex file you generated earlier.
8. Now start the simulation and press START/STOP switch to start the voting process.
9.Now press any party's switch to cast a vote to that party.
10.To end the voting process press START/STOP switch again.
11. The Results will be displayed.
# Running Test File directly
To directly run the votingmachine.c file present in test folder copy the lib folder into the test folder.
# Future Versions
Future versions will include extending the voting machine for more number of parties and improving the user interface.

