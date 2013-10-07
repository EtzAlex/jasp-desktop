#include "anovaoneway.h"

#include "options.h"
#include "option.h"
#include "options/optionfields.h"
#include "options/optionboolean.h"
#include "options/optioninteger.h"
#include "options/optionintegerarray.h"
#include "options/optionlist.h"
#include "options/optionnumber.h"
#include "options/optionfield.h"

using namespace analyses;

AnovaOneWay::AnovaOneWay(int id)
	: Analysis(id, "AnovaOneWay")
{
}

Options *AnovaOneWay::createDefaultOptions()
{
	Options *options = new Options();

	options->add(new OptionFields("variables"));
	options->add(new OptionField("groupingVariable"));
	options->add(new OptionList("equalityOfVariances", "assumeEqual"));
	options->add(new OptionBoolean("testUnequalVariances"));

	options->add(new OptionBoolean("meanDifference"));
	options->add(new OptionBoolean("confidenceInterval"));
	options->add(new OptionNumber("confidenceIntervalInterval", .95, 0, 1, "%"));
	options->add(new OptionBoolean("descriptives"));

	options->add(new OptionList("missingValues", "excludeAnalysisByAnalysis"));

	options->add(new OptionList("tails", "twoTailed"));

	return options;
}