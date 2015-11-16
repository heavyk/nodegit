#ifndef GITREFLOG_H
#define GITREFLOG_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/oid.h"
#include "../include/signature.h"
#include "../include/repository.h"
#include "../include/reflog_entry.h"
// Forward declaration.
struct git_reflog {
};

using namespace node;
using namespace v8;

class GitReflog : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_reflog *GetValue();
    git_reflog **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                                                   

  private:


    GitReflog(git_reflog *raw, bool selfFreeing);
    ~GitReflog();
                                                   
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Append);

    static NAN_METHOD(Delete);

    static NAN_METHOD(Drop);

    static NAN_METHOD(EntryByindex);

    static NAN_METHOD(EntryCommitter);

    static NAN_METHOD(EntryIdNew);

    static NAN_METHOD(EntryIdOld);

    static NAN_METHOD(EntryMessage);

    static NAN_METHOD(Entrycount);

    static NAN_METHOD(Free);

    struct ReadBaton {
      int error_code;
      const git_error* error;
      git_reflog * out;
      git_repository * repo;
      const char * name;
    };
    class ReadWorker : public Nan::AsyncWorker {
      public:
        ReadWorker(
            ReadBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~ReadWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        ReadBaton *baton;
    };

    static NAN_METHOD(Read);

    static NAN_METHOD(Rename);

    static NAN_METHOD(Write);
    git_reflog *raw;
};

#endif
