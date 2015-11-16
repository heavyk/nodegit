#ifndef GITTRANSFERPROGRESS_H
#define GITTRANSFERPROGRESS_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitTransferProgress : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_transfer_progress *GetValue();
    git_transfer_progress **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitTransferProgress(git_transfer_progress *raw, bool selfFreeing);
    ~GitTransferProgress();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(TotalObjects);
    static NAN_METHOD(IndexedObjects);
    static NAN_METHOD(ReceivedObjects);
    static NAN_METHOD(LocalObjects);
    static NAN_METHOD(TotalDeltas);
    static NAN_METHOD(IndexedDeltas);
    static NAN_METHOD(ReceivedBytes);
    git_transfer_progress *raw;
};

#endif
