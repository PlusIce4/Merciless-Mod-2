/**************************************************************************
MERCILESS MOD 2 V3.4+
Current Work by PlusIce (Github: PlusIce4)
Previous Work by Merciless Mod Team (v2.0), Bloodlust (v3.3)
See works cited for full credits
(https://github.com/PlusIce4/Merciless-Mod-2)
**************************************************************************/
//Used to save stuff such as codam player ranking ect.

write()
{
	//Writing to a file
	f = OpenFile("test.txt", "write"); //int OpenFile(string filename, string readmode) readmode = "read", "write", "append"
	//fprintln(f, "Hello World"+"\n"); //void fprintln (int file, string text) Writes a csv line, ie. "Hello World!,"
	text=("wqeqwd");

	fprintln(f,text);
	closefile(f); //void closefile(int file) Closes the file and clears the buffer. DO NOT forget to do this, can cause errors if you don't!
}
read()
{
	//Reading From a File
	e = OpenFile("test.txt", "read");
	lines = freadln(e); //int freadln(int file) Returns the number of CSV elements in the file - only works the first time on a file, returns -1 afterwords.

	//fgetarg(e, 0); //string fgetarg (int file, int arg) Returns the contents of the CSV element at position arg.
	//An Example:
	//iprintln(lines + " total lines");
	for (i = 0; i < lines; i++)
	{
		a[i] = fgetarg(e, i);
		//iprintlnbold("Line " + i + ": " + a[i]);
		iprintlnbold(a[i]);
	}
	CloseFile(e);
}