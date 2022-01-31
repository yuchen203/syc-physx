#include<iostream>
#include "Utilities/ArgsParser.h"
#include "Utilities/Types.h"

#include "Graphics/GlApp.h"
using namespace PhysX;

inline std::unique_ptr<ArgsParser> BuildArgsParser()
{
	auto parser = std::make_unique<ArgsParser>();
	parser->addArgument<std::string>("output", 'o', "the output directory", "output");
	parser->addArgument<uint>("rate", 'r', "the frame rate (frames per second)", 50);
	parser->addArgument<bool>("test", 't', "test", 0);
	return parser;
}

int main(int argc, char *argv[])
{
	auto parser = BuildArgsParser();
	parser->parse(argc, argv);

	const auto output = std::any_cast<std::string>(parser->getValueByName("output"));
	const auto rate = std::any_cast<uint>(parser->getValueByName("rate"));

	auto glApp = std::make_unique<GlApp>(800, 600, "syc");
	glApp->run();
	return 0;
}
