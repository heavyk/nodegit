#ifndef GITSUBMODULE_H
#define GITSUBMODULE_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/repository.h"
#include "../include/oid.h"
#include "../include/buf.h"
#include "../include/submodule_update_options.h"
// Forward declaration.
struct git_submodule {
};

using namespace node;
using namespace v8;

class GitSubmodule : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_submodule *GetValue();
    git_submodule **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                                                                                                                   

  private:


    GitSubmodule(git_submodule *raw, bool selfFreeing);
    ~GitSubmodule();
                                                                                                                   
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(AddFinalize);

    struct AddSetupBaton {
      int error_code;
      const git_error* error;
      git_submodule * out;
      git_repository * repo;
      const char * url;
      const char * path;
      int use_gitlink;
    };
    class AddSetupWorker : public Nan::AsyncWorker {
      public:
        AddSetupWorker(
            AddSetupBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~AddSetupWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        AddSetupBaton *baton;
    };

    static NAN_METHOD(AddSetup);

    static NAN_METHOD(AddToIndex);

    static NAN_METHOD(Branch);

    static NAN_METHOD(FetchRecurseSubmodules);

    static NAN_METHOD(Free);

    static NAN_METHOD(HeadId);

    static NAN_METHOD(Ignore);

    static NAN_METHOD(IndexId);

    static NAN_METHOD(Init);

    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_submodule * out;
      git_repository * repo;
      const char * name;
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

    static NAN_METHOD(Name);

    static NAN_METHOD(Open);

    static NAN_METHOD(Owner);

    static NAN_METHOD(Path);

    static NAN_METHOD(Reload);

    struct RepoInitBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      const git_submodule * sm;
      int use_gitlink;
    };
    class RepoInitWorker : public Nan::AsyncWorker {
      public:
        RepoInitWorker(
            RepoInitBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~RepoInitWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        RepoInitBaton *baton;
    };

    static NAN_METHOD(RepoInit);

    struct ResolveUrlBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      git_repository * repo;
      const char * url;
    };
    class ResolveUrlWorker : public Nan::AsyncWorker {
      public:
        ResolveUrlWorker(
            ResolveUrlBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~ResolveUrlWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        ResolveUrlBaton *baton;
    };

    static NAN_METHOD(ResolveUrl);

    static NAN_METHOD(SetBranch);

    static NAN_METHOD(SetFetchRecurseSubmodules);

    static NAN_METHOD(SetIgnore);

    static NAN_METHOD(SetUpdate);

    static NAN_METHOD(SetUrl);

    static NAN_METHOD(Sync);

    static NAN_METHOD(Update);

    static NAN_METHOD(UpdateInitOptions);

    static NAN_METHOD(UpdateStrategy);

    static NAN_METHOD(Url);

    static NAN_METHOD(WdId);
    git_submodule *raw;
};

#endif
