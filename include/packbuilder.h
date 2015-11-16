#ifndef GITPACKBUILDER_H
#define GITPACKBUILDER_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/oid.h"
#include "../include/revwalk.h"
#include "../include/repository.h"
// Forward declaration.
struct git_packbuilder {
};

using namespace node;
using namespace v8;

class GitPackbuilder : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_packbuilder *GetValue();
    git_packbuilder **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                                           

  private:


    GitPackbuilder(git_packbuilder *raw, bool selfFreeing);
    ~GitPackbuilder();
                                           
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Free);

    static NAN_METHOD(Hash);

    static NAN_METHOD(Insert);

    static NAN_METHOD(InsertCommit);

    static NAN_METHOD(InsertRecur);

    static NAN_METHOD(InsertTree);

    static NAN_METHOD(InsertWalk);

    static NAN_METHOD(Create);

    static NAN_METHOD(ObjectCount);

    static NAN_METHOD(SetThreads);

    static NAN_METHOD(Written);
    git_packbuilder *raw;
};

#endif
