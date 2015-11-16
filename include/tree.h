#ifndef GITTREE_H
#define GITTREE_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/oid.h"
#include "../include/tree_entry.h"
#include "../include/object.h"
#include "../include/repository.h"
// Forward declaration.
struct git_tree {
};

using namespace node;
using namespace v8;

class GitTree : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_tree *GetValue();
    git_tree **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                                                                     

  private:


    GitTree(git_tree *raw, bool selfFreeing);
    ~GitTree();
                                                                     
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(EntryByid);

    static NAN_METHOD(EntryByindex);

    static NAN_METHOD(EntryByname);

    struct EntryBypathBaton {
      int error_code;
      const git_error* error;
      git_tree_entry * out;
      const git_tree * root;
      const char * path;
    };
    class EntryBypathWorker : public Nan::AsyncWorker {
      public:
        EntryBypathWorker(
            EntryBypathBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~EntryBypathWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        EntryBypathBaton *baton;
    };

    static NAN_METHOD(EntryBypath);

    static NAN_METHOD(EntryCmp);

    static NAN_METHOD(EntryDup);

    static NAN_METHOD(EntryFilemode);

    static NAN_METHOD(EntryFilemodeRaw);

    static NAN_METHOD(EntryId);

    static NAN_METHOD(EntryName);

    static NAN_METHOD(EntryToObject);

    static NAN_METHOD(EntryType);

    static NAN_METHOD(Entrycount);

    static NAN_METHOD(Free);

    static NAN_METHOD(Id);

    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_tree * out;
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

    struct LookupPrefixBaton {
      int error_code;
      const git_error* error;
      git_tree * out;
      git_repository * repo;
      const git_oid * id;
      bool idNeedsFree;
      size_t len;
    };
    class LookupPrefixWorker : public Nan::AsyncWorker {
      public:
        LookupPrefixWorker(
            LookupPrefixBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~LookupPrefixWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        LookupPrefixBaton *baton;
    };

    static NAN_METHOD(LookupPrefix);

    static NAN_METHOD(Owner);
    git_tree *raw;
};

#endif
