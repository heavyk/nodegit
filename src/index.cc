// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/index.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/str_array_converter.h"
  #include "../include/index_entry.h"
  #include "../include/strarray.h"
  #include "../include/oid.h"
  #include "../include/repository.h"
  #include "../include/tree.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitIndex::GitIndex(git_index *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitIndex::~GitIndex() {
      if (this->selfFreeing) {
        git_index_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                                                                                                }

  void GitIndex::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Index").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "add", Add);
            Nan::SetPrototypeMethod(tpl, "addAll", AddAll);
            Nan::SetPrototypeMethod(tpl, "addByPath", AddBypath);
            Nan::SetPrototypeMethod(tpl, "caps", Caps);
            Nan::SetPrototypeMethod(tpl, "checksum", Checksum);
            Nan::SetPrototypeMethod(tpl, "clear", Clear);
            Nan::SetPrototypeMethod(tpl, "conflictAdd", ConflictAdd);
            Nan::SetPrototypeMethod(tpl, "conflictCleanup", ConflictCleanup);
            Nan::SetPrototypeMethod(tpl, "conflictGet", ConflictGet);
            Nan::SetPrototypeMethod(tpl, "conflictRemove", ConflictRemove);
             Nan::SetMethod(tpl, "entryIsConflict", EntryIsConflict);
             Nan::SetMethod(tpl, "entryStage", EntryStage);
            Nan::SetPrototypeMethod(tpl, "entryCount", Entrycount);
            Nan::SetPrototypeMethod(tpl, "getByIndex", GetByindex);
            Nan::SetPrototypeMethod(tpl, "getByPath", GetBypath);
            Nan::SetPrototypeMethod(tpl, "hasConflicts", HasConflicts);
             Nan::SetMethod(tpl, "open", Open);
            Nan::SetPrototypeMethod(tpl, "owner", Owner);
            Nan::SetPrototypeMethod(tpl, "path", Path);
            Nan::SetPrototypeMethod(tpl, "read", Read);
            Nan::SetPrototypeMethod(tpl, "readTree", ReadTree);
            Nan::SetPrototypeMethod(tpl, "remove", Remove);
            Nan::SetPrototypeMethod(tpl, "removeAll", RemoveAll);
            Nan::SetPrototypeMethod(tpl, "removeByPath", RemoveBypath);
            Nan::SetPrototypeMethod(tpl, "removeDirectory", RemoveDirectory);
            Nan::SetPrototypeMethod(tpl, "setCaps", SetCaps);
            Nan::SetPrototypeMethod(tpl, "updateAll", UpdateAll);
            Nan::SetPrototypeMethod(tpl, "write", Write);
            Nan::SetPrototypeMethod(tpl, "writeTree", WriteTree);
            Nan::SetPrototypeMethod(tpl, "writeTreeTo", WriteTreeTo);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Index").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitIndex::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitIndex cannot be instantiated.");
     }

    GitIndex* object = new GitIndex(static_cast<git_index *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitIndex::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitIndex::constructor_template), 2, argv).ToLocalChecked());
  }

  git_index *GitIndex::GetValue() {
    return this->raw;
  }

  git_index **GitIndex::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitIndex::ClearValue() {
    this->raw = NULL;
  }

  
/*
   * @param IndexEntry source_entry
     * @return Number  result    */
NAN_METHOD(GitIndex::Add) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("IndexEntry source_entry is required.");
  }

// start convert_from_v8 block
  const git_index_entry * from_source_entry;
  from_source_entry = Nan::ObjectWrap::Unwrap<GitIndexEntry>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   int result = git_index_add(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
,from_source_entry
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
   * @param Strarray pathspec
   * @param Number flags
   * @param IndexMatchedPathCb callback
   * @param Void payload
     */
NAN_METHOD(GitIndex::AddAll) {

  if (info.Length() == 4 || !info[4]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  AddAllBaton* baton = new AddAllBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  AddAll_globalPayload* globalPayload = new AddAll_globalPayload;
  baton->index = Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue();
// start convert_from_v8 block
  const git_strarray * from_pathspec;

  from_pathspec = StrArrayConverter::Convert(info[0]);
// end convert_from_v8 block
  baton->pathspec = from_pathspec;
// start convert_from_v8 block
  unsigned int from_flags;
    if (info[1]->IsNumber()) {
  from_flags = (unsigned int)   info[1]->ToNumber()->Value();
  }
  else {
    from_flags = 0;
  }
// end convert_from_v8 block
  baton->flags = from_flags;
  if (!info[2]->IsFunction()) {
    baton->callback = NULL;
    globalPayload->callback = NULL;
  }
  else {
    baton->callback = AddAll_callback_cppCallback;
    globalPayload->callback = new Nan::Callback(info[2].As<Function>());
  }
  baton->payload = globalPayload;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[4]));
  AddAllWorker *worker = new AddAllWorker(baton, callback);
  worker->SaveToPersistent("index", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("pathspec", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("flags", info[1]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("payload", info[3]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitIndex::AddAllWorker::Execute() {
  int result = git_index_add_all(
baton->index,baton->pathspec,baton->flags,baton->callback,baton->payload    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitIndex::AddAllWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> result = Nan::Undefined();
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("pathspec"));
      workerArguments.push(GetFromPersistent("flags"));
      workerArguments.push(GetFromPersistent("payload"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method addAll has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }

  delete (AddAll_globalPayload*)baton->payload;

  delete baton;
}


int GitIndex::AddAll_callback_cppCallback (
    const char * path,     const char * matched_pathspec,     void * payload  ) {
  AddAll_CallbackBaton* baton = new AddAll_CallbackBaton();

    baton->path = path;
    baton->matched_pathspec = matched_pathspec;
    baton->payload = payload;
 
  baton->result = 0;
  baton->req.data = baton;
  baton->done = false;

  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) AddAll_callback_async);
  uv_async_send(&baton->req);

  while(!baton->done) {
    sleep_for_ms(1);
  }

  
  return baton->result;
}

void GitIndex::AddAll_callback_async(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  AddAll_CallbackBaton* baton = static_cast<AddAll_CallbackBaton*>(req->data);

    Nan::Callback* callback = ((AddAll_globalPayload*)baton->payload)->callback;
   
  Local<Value> argv[3] = {
          Nan::New(baton->path).ToLocalChecked(),
            Nan::New(baton->matched_pathspec).ToLocalChecked(),
          // payload is null because we can use closure scope in javascript
        Nan::Undefined()
    };

  Nan::TryCatch tryCatch;
  Local<v8::Value> result = callback->Call(3, argv);

  if (result->IsObject() && Nan::Has(result->ToObject(), Nan::New("then").ToLocalChecked()).FromJust()) {
    Local<v8::Value> thenProp = Nan::Get(result->ToObject(), Nan::New("then").ToLocalChecked()).ToLocalChecked();

    if (thenProp->IsFunction()) {
      // we can be reasonbly certain that the result is a promise
      Local<Object> promise = result->ToObject();

      baton->promise.Reset(promise);

      uv_close((uv_handle_t*) &baton->req, (uv_close_cb) AddAll_callback_setupAsyncPromisePolling);
      return;
    }
  }

    if (result.IsEmpty() || result->IsNativeError()) {
      baton->result = -1;
    }
    else if (!result->IsNull() && !result->IsUndefined()) {
       if (result->IsNumber()) {
        baton->result = (int)result->ToNumber()->Value();
      }
      else {
        baton->result = 1;
      }
     }
    else {
      baton->result = 1;
    }
 
  baton->done = true;
  uv_close((uv_handle_t*) &baton->req, NULL);
}

void GitIndex::AddAll_callback_setupAsyncPromisePolling(uv_async_t* req) {
  AddAll_CallbackBaton* baton = static_cast<AddAll_CallbackBaton*>(req->data);
  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) AddAll_callback_asyncPromisePolling);
  uv_async_send(&baton->req);
}

void GitIndex::AddAll_callback_asyncPromisePolling(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  AddAll_CallbackBaton* baton = static_cast<AddAll_CallbackBaton*>(req->data);
  Local<Object> promise = Nan::New<Object>(baton->promise);
  Nan::Callback* isPendingFn = new Nan::Callback(Nan::Get(promise, Nan::New("isPending").ToLocalChecked()).ToLocalChecked().As<Function>());
  Local<Value> argv[1]; // MSBUILD won't assign an array of length 0
  Local<Boolean> isPending = isPendingFn->Call(promise, 0, argv)->ToBoolean();

  if (isPending->Value()) {
    uv_async_send(&baton->req);
    return;
  }

  Nan::Callback* isFulfilledFn = new Nan::Callback(Nan::Get(promise, Nan::New("isFulfilled").ToLocalChecked()).ToLocalChecked().As<Function>());
  Local<Boolean> isFulfilled = isFulfilledFn->Call(promise, 0, argv)->ToBoolean();

  if (isFulfilled->Value()) {
    Nan::Callback* resultFn = new Nan::Callback(Nan::Get(promise, Nan::New("value").ToLocalChecked()).ToLocalChecked().As<Function>());
    Local<v8::Value> result = resultFn->Call(promise, 0, argv);

      if (result.IsEmpty() || result->IsNativeError()) {
        baton->result = -1;
      }
      else if (!result->IsNull() && !result->IsUndefined()) {
         if (result->IsNumber()) {
          baton->result = (int)result->ToNumber()->Value();
        }
        else {
          baton->result = 1;
        }
       }
      else {
        baton->result = 1;
      }
     baton->done = true;
  }
  else {
    // promise was rejected
    GitIndex* instance = static_cast<GitIndex*>(baton->  payload  );
    Local<v8::Object> parent = instance->handle();
    Nan::Callback* reasonFn = new Nan::Callback(Nan::Get(promise, Nan::New("reason").ToLocalChecked()).ToLocalChecked().As<Function>());
    Local<v8::Value> reason = reasonFn->Call(promise, 0, argv);
    parent->SetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked(), reason);

    baton->result = -1;
    baton->done = true;
  }

  uv_close((uv_handle_t*) &baton->req, NULL);
}
   
/*
   * @param String path
     * @return Number  result    */
NAN_METHOD(GitIndex::AddBypath) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[0]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
   int result = git_index_add_bypath(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
,from_path
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitIndex::Caps) {
  Nan::EscapableHandleScope scope;

   int result = git_index_caps(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Oid  result    */
NAN_METHOD(GitIndex::Checksum) {
  Nan::EscapableHandleScope scope;

   const git_oid * result = git_index_checksum(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitOid result
       to = GitOid::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitIndex::Clear) {
  Nan::EscapableHandleScope scope;

   int result = git_index_clear(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param IndexEntry ancestor_entry
   * @param IndexEntry our_entry
   * @param IndexEntry their_entry
     * @return Number  result    */
NAN_METHOD(GitIndex::ConflictAdd) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("IndexEntry ancestor_entry is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("IndexEntry our_entry is required.");
  }

  if (info.Length() == 2 || !info[2]->IsObject()) {
    return Nan::ThrowError("IndexEntry their_entry is required.");
  }

// start convert_from_v8 block
  const git_index_entry * from_ancestor_entry;
  from_ancestor_entry = Nan::ObjectWrap::Unwrap<GitIndexEntry>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const git_index_entry * from_our_entry;
  from_our_entry = Nan::ObjectWrap::Unwrap<GitIndexEntry>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const git_index_entry * from_their_entry;
  from_their_entry = Nan::ObjectWrap::Unwrap<GitIndexEntry>(info[2]->ToObject())->GetValue();
// end convert_from_v8 block
   int result = git_index_conflict_add(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
,from_ancestor_entry
,from_our_entry
,from_their_entry
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitIndex::ConflictCleanup) {
  Nan::EscapableHandleScope scope;

   int result = git_index_conflict_cleanup(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
      * @param String path
    * @param IndexEntry callback
  * @param IndexEntry callback
  * @param IndexEntry callback
   */
NAN_METHOD(GitIndex::ConflictGet) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ConflictGetBaton* baton = new ConflictGetBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->index = Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue();
// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[0]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
  baton->path = from_path;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  ConflictGetWorker *worker = new ConflictGetWorker(baton, callback);
  worker->SaveToPersistent("index", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("path", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitIndex::ConflictGetWorker::Execute() {
  int result = git_index_conflict_get(
&baton->ancestor_out,&baton->our_out,&baton->their_out,baton->index,baton->path    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitIndex::ConflictGetWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
    Local<Object> result = Nan::New<Object>();
// start convert_to_v8 block
  
  if (baton->ancestor_out != NULL) {
    // GitIndexEntry baton->ancestor_out
       to = GitIndexEntry::New((void *)baton->ancestor_out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Nan::Set(result, Nan::New("ancestor_out").ToLocalChecked(), to);
// start convert_to_v8 block
  
  if (baton->our_out != NULL) {
    // GitIndexEntry baton->our_out
       to = GitIndexEntry::New((void *)baton->our_out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Nan::Set(result, Nan::New("our_out").ToLocalChecked(), to);
// start convert_to_v8 block
  
  if (baton->their_out != NULL) {
    // GitIndexEntry baton->their_out
       to = GitIndexEntry::New((void *)baton->their_out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Nan::Set(result, Nan::New("their_out").ToLocalChecked(), to);
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("path"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method conflictGet has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }

  free((void *)baton->path);

  delete baton;
}

   
/*
   * @param String path
     * @return Number  result    */
NAN_METHOD(GitIndex::ConflictRemove) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[0]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
   int result = git_index_conflict_remove(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
,from_path
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param IndexEntry entry
     * @return Number  result    */
NAN_METHOD(GitIndex::EntryIsConflict) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("IndexEntry entry is required.");
  }

// start convert_from_v8 block
  const git_index_entry * from_entry;
  from_entry = Nan::ObjectWrap::Unwrap<GitIndexEntry>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   int result = git_index_entry_is_conflict(
from_entry
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param IndexEntry entry
     * @return Number  result    */
NAN_METHOD(GitIndex::EntryStage) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("IndexEntry entry is required.");
  }

// start convert_from_v8 block
  const git_index_entry * from_entry;
  from_entry = Nan::ObjectWrap::Unwrap<GitIndexEntry>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   int result = git_index_entry_stage(
from_entry
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitIndex::Entrycount) {
  Nan::EscapableHandleScope scope;

   size_t result = git_index_entrycount(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param Number n
     * @return IndexEntry  result    */
NAN_METHOD(GitIndex::GetByindex) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number n is required.");
  }

// start convert_from_v8 block
  size_t from_n;
  from_n = (size_t)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
   const git_index_entry * result = git_index_get_byindex(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
,from_n
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitIndexEntry result
       to = GitIndexEntry::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param String path
   * @param Number stage
     * @return IndexEntry  result    */
NAN_METHOD(GitIndex::GetBypath) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[0]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
// start convert_from_v8 block
  int from_stage;
    if (info[1]->IsNumber()) {
  from_stage = (int)   info[1]->ToNumber()->Value();
  }
  else {
    from_stage = 0;
  }
// end convert_from_v8 block
   const git_index_entry * result = git_index_get_bypath(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
,from_path
,from_stage
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitIndexEntry result
       to = GitIndexEntry::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitIndex::HasConflicts) {
  Nan::EscapableHandleScope scope;

   int result = git_index_has_conflicts(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
  * @param String index_path
    * @param Index callback
   */
NAN_METHOD(GitIndex::Open) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String index_path is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  OpenBaton* baton = new OpenBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_index_path;

  String::Utf8Value index_path(info[0]->ToString());
  from_index_path = (const char *) strdup(*index_path);
// end convert_from_v8 block
  baton->index_path = from_index_path;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  OpenWorker *worker = new OpenWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("index_path", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitIndex::OpenWorker::Execute() {
  int result = git_index_open(
&baton->out,baton->index_path    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitIndex::OpenWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitIndex baton->out
       to = GitIndex::New((void *)baton->out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("index_path"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method open has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }

  free((void *)baton->index_path);

  delete baton;
}

   
/*
     * @return Repository  result    */
NAN_METHOD(GitIndex::Owner) {
  Nan::EscapableHandleScope scope;

   git_repository * result = git_index_owner(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitRepository result
       to = GitRepository::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return String  result    */
NAN_METHOD(GitIndex::Path) {
  Nan::EscapableHandleScope scope;

   const char * result = git_index_path(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  if (result){
       to = Nan::New<String>(result).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param Number force
     * @return Number  result    */
NAN_METHOD(GitIndex::Read) {
  Nan::EscapableHandleScope scope;

// start convert_from_v8 block
  int from_force;
    if (info[0]->IsNumber()) {
  from_force = (int)   info[0]->ToNumber()->Value();
  }
  else {
    from_force = 0;
  }
// end convert_from_v8 block
   int result = git_index_read(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
,from_force
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param Tree tree
     * @return Number  result    */
NAN_METHOD(GitIndex::ReadTree) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Tree tree is required.");
  }

// start convert_from_v8 block
  const git_tree * from_tree;
  from_tree = Nan::ObjectWrap::Unwrap<GitTree>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   int result = git_index_read_tree(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
,from_tree
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param String path
   * @param Number stage
     * @return Number  result    */
NAN_METHOD(GitIndex::Remove) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number stage is required.");
  }

// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[0]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
// start convert_from_v8 block
  int from_stage;
  from_stage = (int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_index_remove(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
,from_path
,from_stage
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
   * @param Strarray pathspec
   * @param IndexMatchedPathCb callback
   * @param Void payload
     */
NAN_METHOD(GitIndex::RemoveAll) {

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  RemoveAllBaton* baton = new RemoveAllBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  RemoveAll_globalPayload* globalPayload = new RemoveAll_globalPayload;
  baton->index = Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue();
// start convert_from_v8 block
  const git_strarray * from_pathspec;

  from_pathspec = StrArrayConverter::Convert(info[0]);
// end convert_from_v8 block
  baton->pathspec = from_pathspec;
  if (!info[1]->IsFunction()) {
    baton->callback = NULL;
    globalPayload->callback = NULL;
  }
  else {
    baton->callback = RemoveAll_callback_cppCallback;
    globalPayload->callback = new Nan::Callback(info[1].As<Function>());
  }
  baton->payload = globalPayload;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  RemoveAllWorker *worker = new RemoveAllWorker(baton, callback);
  worker->SaveToPersistent("index", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("pathspec", info[0]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("payload", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitIndex::RemoveAllWorker::Execute() {
  int result = git_index_remove_all(
baton->index,baton->pathspec,baton->callback,baton->payload    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitIndex::RemoveAllWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> result = Nan::Undefined();
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("pathspec"));
      workerArguments.push(GetFromPersistent("payload"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method removeAll has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }

  delete (RemoveAll_globalPayload*)baton->payload;

  delete baton;
}


int GitIndex::RemoveAll_callback_cppCallback (
    const char * path,     const char * matched_pathspec,     void * payload  ) {
  RemoveAll_CallbackBaton* baton = new RemoveAll_CallbackBaton();

    baton->path = path;
    baton->matched_pathspec = matched_pathspec;
    baton->payload = payload;
 
  baton->result = 0;
  baton->req.data = baton;
  baton->done = false;

  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) RemoveAll_callback_async);
  uv_async_send(&baton->req);

  while(!baton->done) {
    sleep_for_ms(1);
  }

  
  return baton->result;
}

void GitIndex::RemoveAll_callback_async(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  RemoveAll_CallbackBaton* baton = static_cast<RemoveAll_CallbackBaton*>(req->data);

    Nan::Callback* callback = ((RemoveAll_globalPayload*)baton->payload)->callback;
   
  Local<Value> argv[3] = {
          Nan::New(baton->path).ToLocalChecked(),
            Nan::New(baton->matched_pathspec).ToLocalChecked(),
          // payload is null because we can use closure scope in javascript
        Nan::Undefined()
    };

  Nan::TryCatch tryCatch;
  Local<v8::Value> result = callback->Call(3, argv);

  if (result->IsObject() && Nan::Has(result->ToObject(), Nan::New("then").ToLocalChecked()).FromJust()) {
    Local<v8::Value> thenProp = Nan::Get(result->ToObject(), Nan::New("then").ToLocalChecked()).ToLocalChecked();

    if (thenProp->IsFunction()) {
      // we can be reasonbly certain that the result is a promise
      Local<Object> promise = result->ToObject();

      baton->promise.Reset(promise);

      uv_close((uv_handle_t*) &baton->req, (uv_close_cb) RemoveAll_callback_setupAsyncPromisePolling);
      return;
    }
  }

    if (result.IsEmpty() || result->IsNativeError()) {
      baton->result = -1;
    }
    else if (!result->IsNull() && !result->IsUndefined()) {
       if (result->IsNumber()) {
        baton->result = (int)result->ToNumber()->Value();
      }
      else {
        baton->result = 1;
      }
     }
    else {
      baton->result = 1;
    }
 
  baton->done = true;
  uv_close((uv_handle_t*) &baton->req, NULL);
}

void GitIndex::RemoveAll_callback_setupAsyncPromisePolling(uv_async_t* req) {
  RemoveAll_CallbackBaton* baton = static_cast<RemoveAll_CallbackBaton*>(req->data);
  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) RemoveAll_callback_asyncPromisePolling);
  uv_async_send(&baton->req);
}

void GitIndex::RemoveAll_callback_asyncPromisePolling(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  RemoveAll_CallbackBaton* baton = static_cast<RemoveAll_CallbackBaton*>(req->data);
  Local<Object> promise = Nan::New<Object>(baton->promise);
  Nan::Callback* isPendingFn = new Nan::Callback(Nan::Get(promise, Nan::New("isPending").ToLocalChecked()).ToLocalChecked().As<Function>());
  Local<Value> argv[1]; // MSBUILD won't assign an array of length 0
  Local<Boolean> isPending = isPendingFn->Call(promise, 0, argv)->ToBoolean();

  if (isPending->Value()) {
    uv_async_send(&baton->req);
    return;
  }

  Nan::Callback* isFulfilledFn = new Nan::Callback(Nan::Get(promise, Nan::New("isFulfilled").ToLocalChecked()).ToLocalChecked().As<Function>());
  Local<Boolean> isFulfilled = isFulfilledFn->Call(promise, 0, argv)->ToBoolean();

  if (isFulfilled->Value()) {
    Nan::Callback* resultFn = new Nan::Callback(Nan::Get(promise, Nan::New("value").ToLocalChecked()).ToLocalChecked().As<Function>());
    Local<v8::Value> result = resultFn->Call(promise, 0, argv);

      if (result.IsEmpty() || result->IsNativeError()) {
        baton->result = -1;
      }
      else if (!result->IsNull() && !result->IsUndefined()) {
         if (result->IsNumber()) {
          baton->result = (int)result->ToNumber()->Value();
        }
        else {
          baton->result = 1;
        }
       }
      else {
        baton->result = 1;
      }
     baton->done = true;
  }
  else {
    // promise was rejected
    GitIndex* instance = static_cast<GitIndex*>(baton->  payload  );
    Local<v8::Object> parent = instance->handle();
    Nan::Callback* reasonFn = new Nan::Callback(Nan::Get(promise, Nan::New("reason").ToLocalChecked()).ToLocalChecked().As<Function>());
    Local<v8::Value> reason = reasonFn->Call(promise, 0, argv);
    parent->SetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked(), reason);

    baton->result = -1;
    baton->done = true;
  }

  uv_close((uv_handle_t*) &baton->req, NULL);
}
   
/*
   * @param String path
     * @return Number  result    */
NAN_METHOD(GitIndex::RemoveBypath) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[0]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
   int result = git_index_remove_bypath(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
,from_path
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param String dir
   * @param Number stage
     * @return Number  result    */
NAN_METHOD(GitIndex::RemoveDirectory) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String dir is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number stage is required.");
  }

// start convert_from_v8 block
  const char * from_dir;

  String::Utf8Value dir(info[0]->ToString());
  from_dir = (const char *) strdup(*dir);
// end convert_from_v8 block
// start convert_from_v8 block
  int from_stage;
  from_stage = (int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_index_remove_directory(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
,from_dir
,from_stage
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param Number caps
     * @return Number  result    */
NAN_METHOD(GitIndex::SetCaps) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number caps is required.");
  }

// start convert_from_v8 block
  int from_caps;
  from_caps = (int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_index_set_caps(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
,from_caps
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
   * @param Strarray pathspec
   * @param IndexMatchedPathCb callback
   * @param Void payload
     */
NAN_METHOD(GitIndex::UpdateAll) {

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  UpdateAllBaton* baton = new UpdateAllBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  UpdateAll_globalPayload* globalPayload = new UpdateAll_globalPayload;
  baton->index = Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue();
// start convert_from_v8 block
  const git_strarray * from_pathspec;

  from_pathspec = StrArrayConverter::Convert(info[0]);
// end convert_from_v8 block
  baton->pathspec = from_pathspec;
  if (!info[1]->IsFunction()) {
    baton->callback = NULL;
    globalPayload->callback = NULL;
  }
  else {
    baton->callback = UpdateAll_callback_cppCallback;
    globalPayload->callback = new Nan::Callback(info[1].As<Function>());
  }
  baton->payload = globalPayload;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  UpdateAllWorker *worker = new UpdateAllWorker(baton, callback);
  worker->SaveToPersistent("index", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("pathspec", info[0]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("payload", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitIndex::UpdateAllWorker::Execute() {
  int result = git_index_update_all(
baton->index,baton->pathspec,baton->callback,baton->payload    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitIndex::UpdateAllWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> result = Nan::Undefined();
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("pathspec"));
      workerArguments.push(GetFromPersistent("payload"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method updateAll has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }

  delete (UpdateAll_globalPayload*)baton->payload;

  delete baton;
}


int GitIndex::UpdateAll_callback_cppCallback (
    const char * path,     const char * matched_pathspec,     void * payload  ) {
  UpdateAll_CallbackBaton* baton = new UpdateAll_CallbackBaton();

    baton->path = path;
    baton->matched_pathspec = matched_pathspec;
    baton->payload = payload;
 
  baton->result = 0;
  baton->req.data = baton;
  baton->done = false;

  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) UpdateAll_callback_async);
  uv_async_send(&baton->req);

  while(!baton->done) {
    sleep_for_ms(1);
  }

  
  return baton->result;
}

void GitIndex::UpdateAll_callback_async(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  UpdateAll_CallbackBaton* baton = static_cast<UpdateAll_CallbackBaton*>(req->data);

    Nan::Callback* callback = ((UpdateAll_globalPayload*)baton->payload)->callback;
   
  Local<Value> argv[3] = {
          Nan::New(baton->path).ToLocalChecked(),
            Nan::New(baton->matched_pathspec).ToLocalChecked(),
          // payload is null because we can use closure scope in javascript
        Nan::Undefined()
    };

  Nan::TryCatch tryCatch;
  Local<v8::Value> result = callback->Call(3, argv);

  if (result->IsObject() && Nan::Has(result->ToObject(), Nan::New("then").ToLocalChecked()).FromJust()) {
    Local<v8::Value> thenProp = Nan::Get(result->ToObject(), Nan::New("then").ToLocalChecked()).ToLocalChecked();

    if (thenProp->IsFunction()) {
      // we can be reasonbly certain that the result is a promise
      Local<Object> promise = result->ToObject();

      baton->promise.Reset(promise);

      uv_close((uv_handle_t*) &baton->req, (uv_close_cb) UpdateAll_callback_setupAsyncPromisePolling);
      return;
    }
  }

    if (result.IsEmpty() || result->IsNativeError()) {
      baton->result = -1;
    }
    else if (!result->IsNull() && !result->IsUndefined()) {
       if (result->IsNumber()) {
        baton->result = (int)result->ToNumber()->Value();
      }
      else {
        baton->result = 1;
      }
     }
    else {
      baton->result = 1;
    }
 
  baton->done = true;
  uv_close((uv_handle_t*) &baton->req, NULL);
}

void GitIndex::UpdateAll_callback_setupAsyncPromisePolling(uv_async_t* req) {
  UpdateAll_CallbackBaton* baton = static_cast<UpdateAll_CallbackBaton*>(req->data);
  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) UpdateAll_callback_asyncPromisePolling);
  uv_async_send(&baton->req);
}

void GitIndex::UpdateAll_callback_asyncPromisePolling(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  UpdateAll_CallbackBaton* baton = static_cast<UpdateAll_CallbackBaton*>(req->data);
  Local<Object> promise = Nan::New<Object>(baton->promise);
  Nan::Callback* isPendingFn = new Nan::Callback(Nan::Get(promise, Nan::New("isPending").ToLocalChecked()).ToLocalChecked().As<Function>());
  Local<Value> argv[1]; // MSBUILD won't assign an array of length 0
  Local<Boolean> isPending = isPendingFn->Call(promise, 0, argv)->ToBoolean();

  if (isPending->Value()) {
    uv_async_send(&baton->req);
    return;
  }

  Nan::Callback* isFulfilledFn = new Nan::Callback(Nan::Get(promise, Nan::New("isFulfilled").ToLocalChecked()).ToLocalChecked().As<Function>());
  Local<Boolean> isFulfilled = isFulfilledFn->Call(promise, 0, argv)->ToBoolean();

  if (isFulfilled->Value()) {
    Nan::Callback* resultFn = new Nan::Callback(Nan::Get(promise, Nan::New("value").ToLocalChecked()).ToLocalChecked().As<Function>());
    Local<v8::Value> result = resultFn->Call(promise, 0, argv);

      if (result.IsEmpty() || result->IsNativeError()) {
        baton->result = -1;
      }
      else if (!result->IsNull() && !result->IsUndefined()) {
         if (result->IsNumber()) {
          baton->result = (int)result->ToNumber()->Value();
        }
        else {
          baton->result = 1;
        }
       }
      else {
        baton->result = 1;
      }
     baton->done = true;
  }
  else {
    // promise was rejected
    GitIndex* instance = static_cast<GitIndex*>(baton->  payload  );
    Local<v8::Object> parent = instance->handle();
    Nan::Callback* reasonFn = new Nan::Callback(Nan::Get(promise, Nan::New("reason").ToLocalChecked()).ToLocalChecked().As<Function>());
    Local<v8::Value> reason = reasonFn->Call(promise, 0, argv);
    parent->SetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked(), reason);

    baton->result = -1;
    baton->done = true;
  }

  uv_close((uv_handle_t*) &baton->req, NULL);
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitIndex::Write) {
  Nan::EscapableHandleScope scope;

   int result = git_index_write(
Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
     * @param Oid callback
   */
NAN_METHOD(GitIndex::WriteTree) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  WriteTreeBaton* baton = new WriteTreeBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->out = (git_oid *)malloc(sizeof(git_oid ));
  baton->index = Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[0]));
  WriteTreeWorker *worker = new WriteTreeWorker(baton, callback);
  worker->SaveToPersistent("index", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitIndex::WriteTreeWorker::Execute() {
  int result = git_index_write_tree(
baton->out,baton->index    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitIndex::WriteTreeWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitOid baton->out
       to = GitOid::New((void *)baton->out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method writeTree has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

  
/*
    * @param Repository repo
    * @param Oid callback
   */
NAN_METHOD(GitIndex::WriteTreeTo) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  WriteTreeToBaton* baton = new WriteTreeToBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->out = (git_oid *)malloc(sizeof(git_oid ));
  baton->index = Nan::ObjectWrap::Unwrap<GitIndex>(info.This())->GetValue();
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  WriteTreeToWorker *worker = new WriteTreeToWorker(baton, callback);
  worker->SaveToPersistent("index", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitIndex::WriteTreeToWorker::Execute() {
  int result = git_index_write_tree_to(
baton->out,baton->index,baton->repo    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitIndex::WriteTreeToWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitOid baton->out
       to = GitOid::New((void *)baton->out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("repo"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method writeTreeTo has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

      Nan::Persistent<Function> GitIndex::constructor_template;
 