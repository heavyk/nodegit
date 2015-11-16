#ifndef GITREPOSITORY_H
#define GITREPOSITORY_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/config.h"
#include "../include/buf.h"
#include "../include/oid.h"
#include "../include/reference.h"
#include "../include/index.h"
#include "../include/repository_init_options.h"
#include "../include/odb.h"
#include "../include/refdb.h"
#include "../include/annotated_commit.h"
// Forward declaration.
struct git_repository {
};

using namespace node;
using namespace v8;

class GitRepository : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_repository *GetValue();
    git_repository **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                      static int FetchheadForeach_callback_cppCallback (
      const char * refname
      ,
       const char * remote_url
      ,
       const git_oid * oid
      ,
       unsigned int is_merge
      ,
       void * payload
      );

    static void FetchheadForeach_callback_async(uv_async_t* req, int status);
    static void FetchheadForeach_callback_setupAsyncPromisePolling(uv_async_t* req);
    static void FetchheadForeach_callback_asyncPromisePolling(uv_async_t* req, int status);
    struct FetchheadForeach_CallbackBaton {
      const char * refname;
      const char * remote_url;
      const git_oid * oid;
      unsigned int is_merge;
      void * payload;
 
      uv_async_t req;
      int result;
      Nan::Persistent<Object> promise;
      bool done;
    };
                                                                                                               

  private:


    GitRepository(git_repository *raw, bool selfFreeing);
    ~GitRepository();
                                                                                                                                 
    static NAN_METHOD(JSNewFunction);


    struct ConfigBaton {
      int error_code;
      const git_error* error;
      git_config * out;
      git_repository * repo;
    };
    class ConfigWorker : public Nan::AsyncWorker {
      public:
        ConfigWorker(
            ConfigBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~ConfigWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        ConfigBaton *baton;
    };

    static NAN_METHOD(Config);

    struct ConfigSnapshotBaton {
      int error_code;
      const git_error* error;
      git_config * out;
      git_repository * repo;
    };
    class ConfigSnapshotWorker : public Nan::AsyncWorker {
      public:
        ConfigSnapshotWorker(
            ConfigSnapshotBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~ConfigSnapshotWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        ConfigSnapshotBaton *baton;
    };

    static NAN_METHOD(ConfigSnapshot);

    static NAN_METHOD(DetachHead);

    struct DiscoverBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      const char * start_path;
      int across_fs;
      const char * ceiling_dirs;
    };
    class DiscoverWorker : public Nan::AsyncWorker {
      public:
        DiscoverWorker(
            DiscoverBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~DiscoverWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        DiscoverBaton *baton;
    };

    static NAN_METHOD(Discover);

    struct FetchheadForeachBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_repository_fetchhead_foreach_cb callback;
      void * payload;
    };
    class FetchheadForeachWorker : public Nan::AsyncWorker {
      public:
        FetchheadForeachWorker(
            FetchheadForeachBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~FetchheadForeachWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        FetchheadForeachBaton *baton;
    };

    static NAN_METHOD(FetchheadForeach);

    static NAN_METHOD(Free);

    static NAN_METHOD(GetNamespace);

    struct HeadBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
    };
    class HeadWorker : public Nan::AsyncWorker {
      public:
        HeadWorker(
            HeadBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~HeadWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        HeadBaton *baton;
    };

    static NAN_METHOD(Head);

    static NAN_METHOD(HeadDetached);

    static NAN_METHOD(HeadUnborn);

    struct IndexBaton {
      int error_code;
      const git_error* error;
      git_index * out;
      git_repository * repo;
    };
    class IndexWorker : public Nan::AsyncWorker {
      public:
        IndexWorker(
            IndexBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~IndexWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        IndexBaton *baton;
    };

    static NAN_METHOD(Index);

    struct InitBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      const char * path;
      unsigned int is_bare;
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

    struct InitExtBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      const char * repo_path;
      git_repository_init_options * opts;
    };
    class InitExtWorker : public Nan::AsyncWorker {
      public:
        InitExtWorker(
            InitExtBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~InitExtWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        InitExtBaton *baton;
    };

    static NAN_METHOD(InitExt);

    static NAN_METHOD(IsBare);

    static NAN_METHOD(IsEmpty);

    static NAN_METHOD(IsShallow);

    static NAN_METHOD(MessageRemove);

    struct OdbBaton {
      int error_code;
      const git_error* error;
      git_odb * out;
      git_repository * repo;
    };
    class OdbWorker : public Nan::AsyncWorker {
      public:
        OdbWorker(
            OdbBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~OdbWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        OdbBaton *baton;
    };

    static NAN_METHOD(Odb);

    struct OpenBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      const char * path;
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

    struct OpenBareBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      const char * bare_path;
    };
    class OpenBareWorker : public Nan::AsyncWorker {
      public:
        OpenBareWorker(
            OpenBareBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~OpenBareWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        OpenBareBaton *baton;
    };

    static NAN_METHOD(OpenBare);

    struct OpenExtBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      const char * path;
      unsigned int flags;
      const char * ceiling_dirs;
    };
    class OpenExtWorker : public Nan::AsyncWorker {
      public:
        OpenExtWorker(
            OpenExtBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~OpenExtWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        OpenExtBaton *baton;
    };

    static NAN_METHOD(OpenExt);

    static NAN_METHOD(Path);

    struct RefdbBaton {
      int error_code;
      const git_error* error;
      git_refdb * out;
      git_repository * repo;
    };
    class RefdbWorker : public Nan::AsyncWorker {
      public:
        RefdbWorker(
            RefdbBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~RefdbWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        RefdbBaton *baton;
    };

    static NAN_METHOD(Refdb);

    struct SetHeadBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      const char * refname;
    };
    class SetHeadWorker : public Nan::AsyncWorker {
      public:
        SetHeadWorker(
            SetHeadBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~SetHeadWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        SetHeadBaton *baton;
    };

    static NAN_METHOD(SetHead);

    static NAN_METHOD(SetHeadDetached);

    static NAN_METHOD(SetHeadDetachedFromAnnotated);

    static NAN_METHOD(SetIdent);

    static NAN_METHOD(SetNamespace);

    static NAN_METHOD(SetWorkdir);

    static NAN_METHOD(State);

    static NAN_METHOD(StateCleanup);

    static NAN_METHOD(Workdir);

    struct WrapOdbBaton {
      int error_code;
      const git_error* error;
      git_repository * out;
      git_odb * odb;
    };
    class WrapOdbWorker : public Nan::AsyncWorker {
      public:
        WrapOdbWorker(
            WrapOdbBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~WrapOdbWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        WrapOdbBaton *baton;
    };

    static NAN_METHOD(WrapOdb);

    struct FetchheadForeach_globalPayload {
      Nan::Callback * callback;

      FetchheadForeach_globalPayload() {
        callback = NULL;
      }

      ~FetchheadForeach_globalPayload() {
        if (callback != NULL) {
          delete callback;
        }
      }
    };
    git_repository *raw;
};

#endif
