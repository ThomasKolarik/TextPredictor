#include "Candidate.h"

// Default Constructor
Candidate::Candidate()
{
}

// Copy Constructor
// @param[in] aCopy The Candidate you wish to copy
Candidate::Candidate(const Candidate & aCopy) :
    Confidence_(aCopy.Confidence_),
    Word_(aCopy.Word_)
{
}

// Move Constructor
// @param[in] aCopy The Candidate you wish to move
Candidate::Candidate(const Candidate && aCopy) :
    Confidence_(std::move(aCopy.Confidence_)),
    Word_(std::move(aCopy.Word_))
{
}

// Copy assignment operator
// @param[in] aCopy The Candidate you wish to copy
// @return A copy of the Candidate.
Candidate & Candidate::operator=(const Candidate & aCopy)
{
    Confidence_ = aCopy.Confidence_;
    Word_       = aCopy.Word_;

    return *this;
}

//  Move assignment operator
//  @param[in] aCopy The Candidate you wish to move
//  @return A copy of the Candidate.
Candidate & Candidate::operator=(const Candidate && aCopy)
{
    Confidence_ = std::move(aCopy.Confidence_);
    Word_       = std::move(aCopy.Word_);

    return *this;
}

// A unique constructor when give a confidence and a string.
// @param[in] Confidence The confidence (word count) of the given candidate.
// @param[in] Word       The candidate word.
Candidate::Candidate(
    int Confidence,
    const std::string & Word) :
    Confidence_(Confidence),
    Word_(Word)
{
}

// Returns the confidence for this candidate.
// @return The confidence for this candidate.
int Candidate::getConfidence() const
{
    return Confidence_;
}

// Returns the word for this candidate.
// @return The word for this candidate.
std::string Candidate::getWord() const
{
    return Word_;
}