#ifndef GITANNOTATEDCOMMIT_H
#define GITANNOTATEDCOMMIT_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/repository.h"
#include "../include/oid.h"
#include "../include/reference.h"
// Forward declaration.
struct git_annotated_commit {
};

using namespace node;
using namespace v8;

class GitAnnotatedCommit : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_annotated_commit *GetValue();
    git_annotated_commit **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                             

  private:


    GitAnnotatedCommit(git_annotated_commit *raw, bool selfFreeing);
    ~GitAnnotatedCommit();
                             
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Free);

    struct FromFetchheadBaton {
      int error_code;
      const git_error* error;
      git_annotated_commit * out;
      git_repository * repo;
      const char * branch_name;
      const char * remote_url;
      const git_oid * id;
      bool idNeedsFree;
    };
    class FromFetchheadWorker : public Nan::AsyncWorker {
      public:
        FromFetchheadWorker(
            FromFetchheadBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~FromFetchheadWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        FromFetchheadBaton *baton;
    };

    static NAN_METHOD(FromFetchhead);

    struct FromRefBaton {
      int error_code;
      const git_error* error;
      git_annotated_commit * out;
      git_repository * repo;
      const git_reference * ref;
    };
    class FromRefWorker : public Nan::AsyncWorker {
      public:
        FromRefWorker(
            FromRefBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~FromRefWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        FromRefBaton *baton;
    };

    static NAN_METHOD(FromRef);

    struct FromRevspecBaton {
      int error_code;
      const git_error* error;
      git_annotated_commit * out;
      git_repository * repo;
      const char * revspec;
    };
    class FromRevspecWorker : public Nan::AsyncWorker {
      public:
        FromRevspecWorker(
            FromRevspecBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~FromRevspecWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        FromRevspecBaton *baton;
    };

    static NAN_METHOD(FromRevspec);

    static NAN_METHOD(Id);

    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_annotated_commit * out;
      git_repository * repo;
      const git_oid * id;
      bool idNeedsFree;
    };
    class LookupWorker : public Nan::AsyncWorker {
      public:
        LookupWorker(
            LookupBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~LookupWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        LookupBaton *baton;
    };

    static NAN_METHOD(Lookup);
    git_annotated_commit *raw;
};

#endif
