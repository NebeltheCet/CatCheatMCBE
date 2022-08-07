namespace FileSys {
	inline std::string CheatPath;
	inline std::string LogPath;

	bool doesExist(std::string);
	void CreateCheatDirectory();
	void WriteLogOutput(std::string);
	void CleanCheatLog();
	void Initialize(std::string);
}