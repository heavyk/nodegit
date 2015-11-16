#ifndef GITMERGE_H
#define GITMERGE_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/repository.h"
#include "../include/annotated_commit.h"
#include "../include/merge_options.h"
#include "../include/checkout_options.h"
#include "../include/oid.h"
#include "../include/oidarray.h"
#include "../include/index.h"
#include "../include/commit.h"
#include "../include/merge_file_input.h"
#include "../include/tree.h"

using namespace node;
using namespace v8;

class GitMerge : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    bool selfFreeing;

                                           

  private:


                                           
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Merge);

    struct BaseBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_repository * repo;
      const git_oid * one;
      bool oneNeedsFree;
      const git_oid * two;
      bool twoNeedsFree;
    };
    class BaseWorker : public Nan::AsyncWorker {
      public:
        BaseWorker(
            BaseBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~BaseWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        BaseBaton *baton;
    };

    static NAN_METHOD(Base);

    struct BasesBaton {
      int error_code;
      const git_error* error;
      git_oidarray * out;
      git_repository * repo;
      const git_oid * one;
      bool oneNeedsFree;
      const git_oid * two;
      bool twoNeedsFree;
    };
    class BasesWorker : public Nan::AsyncWorker {
      public:
        BasesWorker(
            BasesBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~BasesWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        BasesBaton *baton;
    };

    static NAN_METHOD(Bases);

    struct CommitsBaton {
      int error_code;
      const git_error* error;
      git_index * out;
      git_repository * repo;
      const git_commit * our_commit;
      const git_commit * their_commit;
      const git_merge_options * opts;
    };
    class CommitsWorker : public Nan::AsyncWorker {
      public:
        CommitsWorker(
            CommitsBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~CommitsWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        CommitsBaton *baton;
    };

    static NAN_METHOD(Commits);

    static NAN_METHOD(FileInitInput);

    static NAN_METHOD(InitOptions);

    struct TreesBaton {
      int error_code;
      const git_error* error;
      git_index * out;
      git_repository * repo;
      const git_tree * ancestor_tree;
      const git_tree * our_tree;
      const git_tree * their_tree;
      const git_merge_options * opts;
    };
    class TreesWorker : public Nan::AsyncWorker {
      public:
        TreesWorker(
            TreesBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~TreesWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        TreesBaton *baton;
    };

    static NAN_METHOD(Trees);
};

#endif
