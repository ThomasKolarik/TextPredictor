#include <algorithm>
#include <iostream>

#include "AutocompleteProvider.h"

//! This is the main testing function for the TextPredictor program. It allows the user to enter
//! phrases, and read from text in order to then get candidate words given a word fragment.
int main()
{
    std::string selection("");
    AutocompleteProvider acp;

    // The main menu selection loop. Will continue until the user selects "exit"
    while (true)
    {
        std::cout << "Please select an option from the following:\n   Train\n   TrainFromFile\n   GetCandidates\n   Exit" << std::endl;

        std::cin >> selection;

        std::transform(selection.begin(), selection.end(), selection.begin(), tolower);

        // Train the AutocompleteProvider using entered phrases.
        if (selection.compare("train") == 0)
        {
            std::cout << "The AutocompleteProvider will now train off of any phrases you enter. If you wish to exit please type '$exit'" << std::endl;

            std::cin >> selection;

            while (selection.compare("$exit") != 0)
            {
                acp.train(selection);
                std::cin >> selection;
            }
        }
        // Train the AutocompleteProvider using a text file.
        else if (selection.compare("trainfromfile") == 0)
        {
            std::cout << "The AutocompleteProvider will now train off of any file you enter. The file must be co-located with this binary. If you wish to exit please type '$exit'" << std::endl;

            std::cin >> selection;

            while (selection.compare("$exit") != 0)
            {
                acp.trainFromFile(selection);
                std::cin >> selection;
            }
        }
        // Provide candidates back to the user given a word fragment. If multiple words are entered
        //  at a time only the first word is used.
        else if (selection.compare("getcandidates") == 0)
        {
            std::cout << "The AutocompleteProvider will now provide the candidates for any word you enter (Case does not matter). If you wish to exit please type '$exit'" << std::endl;

            std::cin >> selection;

            while (selection.compare("$exit") != 0)
            {
                std::vector<Candidate> candidates = acp.getWords(selection);

                for (auto candidate : candidates)
                {
                    std::cout << "\"" << candidate.getWord() << "\" (" << candidate.getConfidence() << ")" << std::endl;
                }

                if (candidates.size() == 0)
                {
                    std::cout << "Found no candidates for " << selection << "." << std::endl;
                }

                std::cin >> selection;
            }
        }
        else if (selection.compare("exit") == 0)
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
    }

    return 0;
}