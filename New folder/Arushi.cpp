#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base class for a file or directory. It holds anything that is common to files and folders.
class FSObject
{
public:
   string location="";



	virtual ~FSObject() {}

	string name; // Only the name of the object, like, "Cloud", "Amazon", "Azure.txt", NOT the full path
};

// This class represents a directory. A directory can have sub-directories or files in it; it does not have any other attributes.
// TODO: Add necessary data structures to this class to implement the functionality needed from a directory object
class FSDirectory : public FSObject
{
	public:
//	static const int count =0;
//   static vector<vector<string>> hierarchy;
//
//	FSDirectory(){
//		if(count==0)
//		{
//
//
//		}
//	}
//	FSDirectory(string st, string parent)
//	{
//		//this->name=name;
//		if(parent!="")
//		hierarchy[parent].push_back(name);
//		else
//		{
//			hierarchy.push_back(st);
//		}
//		
//
//	}

   //static vector<vector<FSDirectory*>> hierarchy;


};

// This class represents a file. A file has data and can have links.
// TODO: Add necessary data structures to this class to implement the functionality needed from a file object
class FSFile : public FSDirectory
{
//	public:
//		string content="";
//
//	FSFile()
//	{
//
//	}
//	FSFile(string name,string content)
//	{
//		this->name=name;
//		this->content=content;
//	}
//	vector<string> links;

};

// "CDrive" object becomes the globally available root of the file system
// TODO: Once you design the FSDirectory class, uncomment this line; if you uncomment it sooner, then there will be a compile error
//FSDirectory CDrive("C:");


// Given a full file path like "C:\Cloud\Cloud.txt" as input, create the additional directory and file objects and link it to the CDrive object
int CreateFile(const string& fullFilePath, const string& data)
{
	// Your code here
//	string st, parent="",content="";
//	cout<<"Enter the content of the file"<<endl;
//	cin>>content;
//	for(int i=3;i<fullFilePath.size();i++)
//	{
//		if(fullFilePath[i]!= const("\\") )
//		{
//			st+=fullFilePath[i];
//
//		}
//		// if present in hierarchy..ignore
//		if(true)
//		{
//			parent=st;
//			st="";
//
//		}
//		else
//		{
//			FSDirectory * fsd= new FSDirectory(st, parent);
//		}
//		
//
//
//
//	}
//	FSFile* fsfile = new FSFile(st);
//

	return 0; // Return value of 0 means success
}

// Print the contents of an existing file like "C:\Cloud\Cloud.txt" to console
int ReadFile(const string& fullFilePath)
{
	// Your code here


	return 0; // Return value of 0 means success
}

// Replace the contents of an existing file like "C:\Cloud\Cloud.txt" with the new data
int ReplaceFileContent(const string& fullFilePath, const string& newData)
{
	// Your code here

	return 0; // Return value of 0 means success
}

// Given a full file path like "C:\Cloud\Cloud.txt" as input, delete the file object representing Cloud.txt; do not delete the ancestors
int DeleteFile(const string& fullFilePath)
{
	// Your code here

	return 0; // Return value of 0 means success
}

// If a new link to an existing file "C:\Cloud\Microsoft\VMware-Azure.txt" is being made at "C:\Cloud\Amazon\VMware-AWS.txt",
// then both 'share' the data; the new link will point to the data of the existing file.
int AddFileLink(const string& existingFilePath, const string& newLinkPath)
{
	// Your code here

	return 0; // Return value of 0 means success
}

// An existing file like "C:\Cloud\Microsoft\Azure.txt" can be moved to different location on the file system, like "C:\Cloud\MSFT\Azure.txt"
int MoveFile(const string& existingFilePath, const string& newFilePath)
{
	// Your code here

	return 0; // Return value of 0 means success
}

// Iterate over the classes / data structures of the file system represented by the root directory "CDrive", and print the full paths of files, one on each line, like
// C:\Cloud\Cloud.txt, "All organizations are moving to the cloud now"
// C:\Cloud\Microsoft\Azure.txt, "Azure is a Microsoft provided cloud"
// ...
void PrintAllFilesInCDrive()
{
	// Your code here
}

int main(int argc, char ** argv)
{
	// Section 1: Create, read, update and delete file
	CreateFile("C:\\Cloud\\Cloud.txt", "Cloud is gaining importance these days");
	ReadFile("C:\\Cloud\\Cloud.txt");
	ReplaceFileContent("C:\\Cloud\\Cloud.txt", "All organizations are moving to the cloud now");
	DeleteFile("C:\\Cloud\\Cloud.txt");

	PrintAllFilesInCDrive();

	CreateFile("C:\\Cloud\\Microsoft\\Azure.txt", "Azure is a Microsoft provided cloud");
	CreateFile("C:\\Cloud\\Amazon\\AWS.txt", "AWS is an Amazon provided cloud");

	// Section 2: Add file link
	CreateFile("C:\\Cloud\\Microsoft\\VMware-Azure.txt", "VMware integrates with both, Azure and AWS");
	ReadFile("C:\\Cloud\\Microsoft\\VMware-Azure.txt");

	AddFileLink("C:\\Cloud\\Microsoft\\VMware-Azure.txt", "C:\\Cloud\\Amazon\\VMware-AWS.txt");
	ReadFile("C:\\Cloud\\Microsoft\\VMware-Azure.txt");

	ReplaceFileContent("C:\\Cloud\\Microsoft\\VMware-AWS.txt", "Many vendors are integrating with multiple cloud providers");
	ReadFile("C:\\Cloud\\Microsoft\\VMware-Azure.txt");
	ReadFile("C:\\Cloud\\Microsoft\\VMware-AWS.txt");

	DeleteFile("C:\\Cloud\\Microsoft\\VMware-Azure.txt");
	DeleteFile("C:\\Cloud\\Amazon\\VMware-AWS.txt");

	PrintAllFilesInCDrive();

	// Section 3: Move file
	MoveFile("C:\\Cloud\\Microsoft\\Azure.txt", "C:\\Cloud\\MSFT\\Azure.txt");

	return 0;
}
