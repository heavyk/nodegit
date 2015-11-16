#ifndef GITREBASE_H
#define GITREBASE_H
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
#include "../include/annotated_commit.h"
#include "../include/rebase_options.h"
#include "../include/rebase_operation.h"
// Forward declaration.
struct git_rebase {
};

using namespace node;
using namespace v8;

class GitRebase : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_rebase *GetValue();
    git_rebase **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                                               

  private:


    GitRebase(git_rebase *raw, bool selfFreeing);
    ~GitRebase();
                                               
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Abort);

    static NAN_METHOD(Commit);

    static NAN_METHOD(Finish);

    struct InitBaton {
      int error_code;
      const git_error* error;
      git_rebase * out;
      git_repository * repo;
      const git_annotated_commit * branch;
      const git_annotated_commit * upstream;
      const git_annotated_commit * onto;
      const git_rebase_options * opts;
    };
    class InitWorker : public Nan::AsyncWorker {
      public:
        InitWorker(
            InitBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~InitWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        InitBaton *baton;
    };

    static NAN_METHOD(Init);

    static NAN_METHOD(InitOptions);

    struct NextBaton {
      int error_code;
      const git_error* error;
      git_rebase_operation * out;
      git_rebase * rebase;
    };
    class NextWorker : public Nan::AsyncWorker {
      public:
        NextWorker(
            NextBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~NextWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        NextBaton *baton;
    };

    static NAN_METHOD(Next);

    struct OpenBaton {
      int error_code;
      const git_error* error;
      git_rebase * out;
      git_repository * repo;
      const git_rebase_options * opts;
    };
    class OpenWorker : public Nan::AsyncWorker {
      public:
        OpenWorker(
            OpenBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~OpenWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        OpenBaton *baton;
    };

    static NAN_METHOD(Open);

    static NAN_METHOD(OperationByindex);

    static NAN_METHOD(OperationCurrent);

    static NAN_METHOD(OperationEntrycount);
    git_rebase *raw;
};

#endif
