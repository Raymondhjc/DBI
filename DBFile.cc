#include "TwoWayList.h"
#include "Record.h"
#include "Schema.h"
#include "File.h"
#include "Comparison.h"
#include "ComparisonEngine.h"
#include "DBFile.h"
#include "Defs.h"

// stub file .. replace it with your own DBFile.cc

DBFile::DBFile()
{
}

int DBFile::Create(const char *f_path, fType f_type, void *startup)
{

    f.Open(0, fp); // open, with 0 to create, giving it the path.

    switch (f_type)
    {
    case heap:
        cout << "file type: heap" << endl;
        break;
    case sorted:
    case tree:
    default:
    }
    return 0;
}

void DBFile::Load(Schema &f_schema, const char *loadpath)
{
    FILE *tableFile = fopen(loadpath, "r");
    if (tableFile == 0)
    {
        exit(-1);
    }
    Record curRecord;
    Page curPage;
    int pageNum = 0;
    int isFull = 1;
    while (curRecord.SuckNextRecord(&f_schema, tableFile) == 1)
    {
        isFull = curPage.Append(&curRecord);
        if (isFull == 0)
        {
            f.AddPage(&curPage, pageNum++);
            curPage.EmptyItOut();
            curPage.Append(&curRecord);
        }
    }
    f.AddPage(&curPage, pageNum++);
}

int DBFile::Open(const char *f_path)
{
    f.Open(1, f_path);
    return 0;
}

void DBFile::MoveFirst()
{
    curPageIndex = (off_t)0;
    f.GetPage(&curPage, curPageIndex);
}

int DBFile::Close()
{
    f.Close() < 0 ? 0 : 1;
}

void DBFile::Add(Record &rec)
{
    
}

int DBFile::GetNext(Record &fetchme)
{
}

int DBFile::GetNext(Record &fetchme, CNF &cnf, Record &literal)
{
}
