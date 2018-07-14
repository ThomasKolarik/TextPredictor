TextPredictor 1.0

Created by: 
Thomas Kolarik

TextPredictor.exe is a tool used to predict what word a user is attempt to
write and it will then provide candidate words for them. This program provides
two different methods for training the predictor in order to make its
prediction. A user can enter phrases on their own or read text files. For the
remainder of the time that the program is open every word that is read will be
used to make its future predictions.

Source should have also been provided. This source is commented using doxygen
style comments, which can be used in order to auto generate documentation.
However, a guide on how to generate this will not be provided.

-------------------------------------------------------------------------------

In order to build:
Microsoft Visual Studio 2017 was used in order to create the 
"TextPredictor.exe" binary file.

If you wish to build it yourself you can open the TextPredictor.sln file, which
will can be used to build the binary.

The source should be able to be built using any modern compiler however it was
only tested using MSVC.

-------------------------------------------------------------------------------

How to use:

Using entered phrases:
1. Open TextPredictor.exe.
2. Type "train" to enter the training menu.
3. Enter words or phrases that you wish to train with (e.g. "This is a test 
   sentence for training purposes.").
4. Type "$exit" in order to exit the training menu.
5. Type "getcandidates" in order to enter the getcandidates menu.
6. Type a word fragment in order to get its candidates (e.g. "t").
7. Observe the candidates with their confidence (the number of times the word
   showed up during training).
8. Type "$exit" again to exit the candidate menu.
9. Type "exit" to exit the program.

Using pre-defined text:
1. Open TextPredictor.exe.
2. Type "trainfromfile" to enter the train from file menu.
3. Enter the file you wish to read in (this file must be co-located with the
   TextPredictor.exe binary).
   I have provided some example books from the Project Gutenberg. This package
   should contain The History of Antiquity, Vol. I-VI, by Max Duncker.
4. Type "$exit" in order to exit the training menu.
5. Type "getcandidates" in order to enter the getcandidates menu.
6. Type a word fragment in order to get its candidates (e.g. "t").
7. Observe the candidates with their confidence (the number of times the word
   showed up during training).
8. Type "$exit" again to exit the candidate menu.
9. Type "exit" to exit the program.