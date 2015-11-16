#ifndef GITINDEX_H
#define GITINDEX_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/str_array_converter.h"
#include "../include/index_entry.h"
#include "../include/strarray.h"
#include "../include/oid.h"
#include "../include/repository.h"
#include "../include/tree.h"
// Forward declaration.
struct git_index {
};

using namespace node;
using namespace v8;

class GitIndex : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_index *GetValue();
    git_index **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

           static int AddAll_callback_cppCallback (
      const char * path
      ,
       const char * matched_pathspec
      ,
       void * payload
      );

    static void AddAll_callback_async(uv_async_t* req, int status);
    static void AddAll_callback_setupAsyncPromisePolling(uv_async_t* req);
    static void AddAll_callback_asyncPromisePolling(uv_async_t* req, int status);
    struct AddAll_CallbackBaton {
      const char * path;
      const char * matched_pathspec;
      void * payload;
 
      uv_async_t req;
      int result;
      Nan::Persistent<Object> promise;
      bool done;
    };
                                                                                       static int RemoveAll_callback_cppCallback (
      const char * path
      ,
       const char * matched_pathspec
      ,
       void * payload
      );

    static void RemoveAll_callback_async(uv_async_t* req, int status);
    static void RemoveAll_callback_setupAsyncPromisePolling(uv_async_t* req);
    static void RemoveAll_callback_asyncPromisePolling(uv_async_t* req, int status);
    struct RemoveAll_CallbackBaton {
      const char * path;
      const char * matched_pathspec;
      void * payload;
 
      uv_async_t req;
      int result;
      Nan::Persistent<Object> promise;
      bool done;
    };
                       static int UpdateAll_callback_cppCallback (
      const char * path
      ,
       const char * matched_pathspec
      ,
       void * payload
      );

    static void UpdateAll_callback_async(uv_async_t* req, int status);
    static void UpdateAll_callback_setupAsyncPromisePolling(uv_async_t* req);
    static void UpdateAll_callback_asyncPromisePolling(uv_async_t* req, int status);
    struct UpdateAll_CallbackBaton {
      const char * path;
      const char * matched_pathspec;
      void * payload;
 
      uv_async_t req;
      int result;
      Nan::Persistent<Object> promise;
      bool done;
    };
                 

  private:


    GitIndex(git_index *raw, bool selfFreeing);
    ~GitIndex();
                                                                                                                              
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Add);

    struct AddAllBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      const git_strarray * pathspec;
      unsigned int flags;
      git_index_matched_path_cb callback;
      void * payload;
    };
    class AddAllWorker : public Nan::AsyncWorker {
      public:
        AddAllWorker(
            AddAllBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~AddAllWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        AddAllBaton *baton;
    };

    static NAN_METHOD(AddAll);

    static NAN_METHOD(AddBypath);

    static NAN_METHOD(Caps);

    static NAN_METHOD(Checksum);

    static NAN_METHOD(Clear);

    static NAN_METHOD(ConflictAdd);

    static NAN_METHOD(ConflictCleanup);

    struct ConflictGetBaton {
      int error_code;
      const git_error* error;
      const git_index_entry * ancestor_out;
      const git_index_entry * our_out;
      const git_index_entry * their_out;
      git_index * index;
      const char * path;
    };
    class ConflictGetWorker : public Nan::AsyncWorker {
      public:
        ConflictGetWorker(
            ConflictGetBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~ConflictGetWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        ConflictGetBaton *baton;
    };

    static NAN_METHOD(ConflictGet);

    static NAN_METHOD(ConflictRemove);

    static NAN_METHOD(EntryIsConflict);

    static NAN_METHOD(EntryStage);

    static NAN_METHOD(Entrycount);

    static NAN_METHOD(GetByindex);

    static NAN_METHOD(GetBypath);

    static NAN_METHOD(HasConflicts);

    struct OpenBaton {
      int error_code;
      const git_error* error;
      git_index * out;
      const char * index_path;
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

    static NAN_METHOD(Owner);

    static NAN_METHOD(Path);

    static NAN_METHOD(Read);

    static NAN_METHOD(ReadTree);

    static NAN_METHOD(Remove);

    struct RemoveAllBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      const git_strarray * pathspec;
      git_index_matched_path_cb callback;
      void * payload;
    };
    class RemoveAllWorker : public Nan::AsyncWorker {
      public:
        RemoveAllWorker(
            RemoveAllBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~RemoveAllWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        RemoveAllBaton *baton;
    };

    static NAN_METHOD(RemoveAll);

    static NAN_METHOD(RemoveBypath);

    static NAN_METHOD(RemoveDirectory);

    static NAN_METHOD(SetCaps);

    struct UpdateAllBaton {
      int error_code;
      const git_error* error;
      git_index * index;
      const git_strarray * pathspec;
      git_index_matched_path_cb callback;
      void * payload;
    };
    class UpdateAllWorker : public Nan::AsyncWorker {
      public:
        UpdateAllWorker(
            UpdateAllBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~UpdateAllWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        UpdateAllBaton *baton;
    };

    static NAN_METHOD(UpdateAll);

    static NAN_METHOD(Write);

    struct WriteTreeBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_index * index;
    };
    class WriteTreeWorker : public Nan::AsyncWorker {
      public:
        WriteTreeWorker(
            WriteTreeBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~WriteTreeWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        WriteTreeBaton *baton;
    };

    static NAN_METHOD(WriteTree);

    struct WriteTreeToBaton {
      int error_code;
      const git_error* error;
      git_oid * out;
      git_index * index;
      git_repository * repo;
    };
    class WriteTreeToWorker : public Nan::AsyncWorker {
      public:
        WriteTreeToWorker(
            WriteTreeToBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~WriteTreeToWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        WriteTreeToBaton *baton;
    };

    static NAN_METHOD(WriteTreeTo);

    struct AddAll_globalPayload {
      Nan::Callback * callback;

      AddAll_globalPayload() {
        callback = NULL;
      }

      ~AddAll_globalPayload() {
        if (callback != NULL) {
          delete callback;
        }
      }
    };

    struct RemoveAll_globalPayload {
      Nan::Callback * callback;

      RemoveAll_globalPayload() {
        callback = NULL;
      }

      ~RemoveAll_globalPayload() {
        if (callback != NULL) {
          delete callback;
        }
      }
    };

    struct UpdateAll_globalPayload {
      Nan::Callback * callback;

      UpdateAll_globalPayload() {
        callback = NULL;
      }

      ~UpdateAll_globalPayload() {
        if (callback != NULL) {
          delete callback;
        }
      }
    };
    git_index *raw;
};

#endif
