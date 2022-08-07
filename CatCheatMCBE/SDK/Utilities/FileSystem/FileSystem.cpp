#include "../../../Includes.hpp"

bool FileSys::doesExist(std::string Name) {
	if (Name.size() <= 0)
		return false;

	return std::filesystem::exists(Name);
}

void FileSys::Initialize(std::string CheatName) { /* If i have the CheatPath somewhere else other than roaming i crash ;C */
	if (CheatName.size() <= 0)
		return;

	std::string AppDataPath = getenv("APPDATA");
	if (AppDataPath.length() <= 0)
		return;

	std::string MCRoamingPath = AppDataPath + std::string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\");
	if (!doesExist(MCRoamingPath))
		return;

	CheatPath = MCRoamingPath + CheatName;
	LogPath = CheatPath + "\\" + CheatName + ".txt";
	CreateCheatDirectory();
	CleanCheatLog();
}

void FileSys::CreateCheatDirectory() {

	std::filesystem::create_directories(CheatPath);
}

void FileSys::WriteLogOutput(std::string CheatOutput) {
	if (!doesExist(CheatPath))
		return;

	if (LogPath.size() <= 0)
		return;

	std::fstream logFile;
	logFile.open(LogPath, std::ios_base::app); /* Anything other than app only prints the last message */
	logFile << CheatOutput << std::endl;
	logFile.close();
}

void FileSys::CleanCheatLog() {
	if (!doesExist(CheatPath))
		return;

	if (LogPath.size() <= 0)
		return;

	std::fstream ClearFile;
	ClearFile.open(LogPath, std::ofstream::out | std::ofstream::trunc);
	ClearFile.close();
}