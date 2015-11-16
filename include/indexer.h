#ifndef GITINDEXER_H
#define GITINDEXER_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/transfer_progress.h"
#include "../include/oid.h"

using namespace node;
using namespace v8;

class GitIndexer : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_indexer *GetValue();
    git_indexer **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

           

  private:


    GitIndexer(git_indexer *raw, bool selfFreeing);
    ~GitIndexer();
           
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Commit);

    static NAN_METHOD(Free);

    static NAN_METHOD(Hash);
    git_indexer *raw;
};

#endif
