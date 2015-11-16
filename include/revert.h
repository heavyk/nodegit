#ifndef GITREVERT_H
#define GITREVERT_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/repository.h"
#include "../include/commit.h"
#include "../include/revert_options.h"
#include "../include/index.h"
#include "../include/merge_options.h"

using namespace node;
using namespace v8;

class GitRevert : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    bool selfFreeing;

              

  private:


              
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Revert);

    struct CommitBaton {
      int error_code;
      const git_error* error;
      git_index * out;
      git_repository * repo;
      git_commit * revert_commit;
      git_commit * our_commit;
      unsigned int mainline;
      const git_merge_options * merge_options;
    };
    class CommitWorker : public Nan::AsyncWorker {
      public:
        CommitWorker(
            CommitBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~CommitWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        CommitBaton *baton;
    };

    static NAN_METHOD(Commit);
};

#endif
