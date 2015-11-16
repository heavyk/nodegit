// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
    #include <git2/sys/diff.h>
 }

#include "../include/functions/copy.h"
#include "../include/status.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/status_list.h"
  #include "../include/status_entry.h"
  #include "../include/repository.h"
  #include "../include/status_options.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

 
  void GitStatus::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<Object> object = Nan::New<Object>();

        Nan::SetMethod(object, "byIndex", Byindex);
         Nan::SetMethod(object, "file", File);
         Nan::SetMethod(object, "foreach", Foreach);
         Nan::SetMethod(object, "foreachExt", ForeachExt);
         Nan::SetMethod(object, "shouldIgnore", ShouldIgnore);
  
    Nan::Set(target, Nan::New<String>("Status").ToLocalChecked(), object);
  }

  
/*
 * @param StatusList statuslist
   * @param Number idx
     * @return StatusEntry  result    */
NAN_METHOD(GitStatus::Byindex) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("StatusList statuslist is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number idx is required.");
  }

// start convert_from_v8 block
  git_status_list * from_statuslist;
  from_statuslist = Nan::ObjectWrap::Unwrap<GitStatusList>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  size_t from_idx;
  from_idx = (size_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
   const git_status_entry * result = git_status_byindex(
from_statuslist
,from_idx
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitStatusEntry result
       to = GitStatusEntry::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
  * @param Repository repo
   * @param String path
     * @return Number status_flags    */
NAN_METHOD(GitStatus::File) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

  unsigned int status_flags = 0;
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[1]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
   int result = git_status_file(
&status_flags
,from_repo
,from_path
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( status_flags);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
 * @param Repository repo
   * @param StatusCb callback
   * @param Void payload
     */
NAN_METHOD(GitStatus::Foreach) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("StatusCb callback is required.");
  }
  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ForeachBaton* baton = new ForeachBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  Foreach_globalPayload* globalPayload = new Foreach_globalPayload;
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
  if (!info[1]->IsFunction()) {
    baton->callback = NULL;
    globalPayload->callback = NULL;
  }
  else {
    baton->callback = Foreach_callback_cppCallback;
    globalPayload->callback = new Nan::Callback(info[1].As<Function>());
  }
  baton->payload = globalPayload;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  ForeachWorker *worker = new ForeachWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("payload", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitStatus::ForeachWorker::Execute() {
  int result = git_status_foreach(
baton->repo,baton->callback,baton->payload    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitStatus::ForeachWorker::HandleOKCallback() {
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
      workerArguments.push(GetFromPersistent("repo"));
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
        Local<v8::Object> err = Nan::Error("Method foreach has thrown an error.")->ToObject();
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

  delete (Foreach_globalPayload*)baton->payload;

  delete baton;
}


int GitStatus::Foreach_callback_cppCallback (
    const char * path,     unsigned int status_flags,     void * payload  ) {
  Foreach_CallbackBaton* baton = new Foreach_CallbackBaton();

    baton->path = path;
    baton->status_flags = status_flags;
    baton->payload = payload;
 
  baton->result = 0;
  baton->req.data = baton;
  baton->done = false;

  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) Foreach_callback_async);
  uv_async_send(&baton->req);

  while(!baton->done) {
    sleep_for_ms(1);
  }

  
  return baton->result;
}

void GitStatus::Foreach_callback_async(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  Foreach_CallbackBaton* baton = static_cast<Foreach_CallbackBaton*>(req->data);

    Nan::Callback* callback = ((Foreach_globalPayload*)baton->payload)->callback;
   
  Local<Value> argv[3] = {
          Nan::New(baton->path).ToLocalChecked(),
             Nan::New(baton->status_flags),
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

      uv_close((uv_handle_t*) &baton->req, (uv_close_cb) Foreach_callback_setupAsyncPromisePolling);
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
        baton->result = 0;
      }
     }
    else {
      baton->result = 0;
    }
 
  baton->done = true;
  uv_close((uv_handle_t*) &baton->req, NULL);
}

void GitStatus::Foreach_callback_setupAsyncPromisePolling(uv_async_t* req) {
  Foreach_CallbackBaton* baton = static_cast<Foreach_CallbackBaton*>(req->data);
  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) Foreach_callback_asyncPromisePolling);
  uv_async_send(&baton->req);
}

void GitStatus::Foreach_callback_asyncPromisePolling(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  Foreach_CallbackBaton* baton = static_cast<Foreach_CallbackBaton*>(req->data);
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
          baton->result = 0;
        }
       }
      else {
        baton->result = 0;
      }
     baton->done = true;
  }
  else {
    // promise was rejected
    GitStatus* instance = static_cast<GitStatus*>(baton->  payload  );
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
 * @param Repository repo
   * @param StatusOptions opts
   * @param StatusCb callback
   * @param Void payload
     */
NAN_METHOD(GitStatus::ForeachExt) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("StatusOptions opts is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("StatusCb callback is required.");
  }
  if (info.Length() == 4 || !info[4]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ForeachExtBaton* baton = new ForeachExtBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  ForeachExt_globalPayload* globalPayload = new ForeachExt_globalPayload;
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const git_status_options * from_opts;
  from_opts = Nan::ObjectWrap::Unwrap<GitStatusOptions>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->opts = from_opts;
  if (!info[2]->IsFunction()) {
    baton->callback = NULL;
    globalPayload->callback = NULL;
  }
  else {
    baton->callback = ForeachExt_callback_cppCallback;
    globalPayload->callback = new Nan::Callback(info[2].As<Function>());
  }
  baton->payload = globalPayload;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[4]));
  ForeachExtWorker *worker = new ForeachExtWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("opts", info[1]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("payload", info[3]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitStatus::ForeachExtWorker::Execute() {
  int result = git_status_foreach_ext(
baton->repo,baton->opts,baton->callback,baton->payload    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitStatus::ForeachExtWorker::HandleOKCallback() {
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
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("opts"));
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
        Local<v8::Object> err = Nan::Error("Method foreachExt has thrown an error.")->ToObject();
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

  delete (ForeachExt_globalPayload*)baton->payload;

  delete baton;
}


int GitStatus::ForeachExt_callback_cppCallback (
    const char * path,     unsigned int status_flags,     void * payload  ) {
  ForeachExt_CallbackBaton* baton = new ForeachExt_CallbackBaton();

    baton->path = path;
    baton->status_flags = status_flags;
    baton->payload = payload;
 
  baton->result = 0;
  baton->req.data = baton;
  baton->done = false;

  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) ForeachExt_callback_async);
  uv_async_send(&baton->req);

  while(!baton->done) {
    sleep_for_ms(1);
  }

  
  return baton->result;
}

void GitStatus::ForeachExt_callback_async(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  ForeachExt_CallbackBaton* baton = static_cast<ForeachExt_CallbackBaton*>(req->data);

    Nan::Callback* callback = ((ForeachExt_globalPayload*)baton->payload)->callback;
   
  Local<Value> argv[3] = {
          Nan::New(baton->path).ToLocalChecked(),
             Nan::New(baton->status_flags),
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

      uv_close((uv_handle_t*) &baton->req, (uv_close_cb) ForeachExt_callback_setupAsyncPromisePolling);
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
        baton->result = 0;
      }
     }
    else {
      baton->result = 0;
    }
 
  baton->done = true;
  uv_close((uv_handle_t*) &baton->req, NULL);
}

void GitStatus::ForeachExt_callback_setupAsyncPromisePolling(uv_async_t* req) {
  ForeachExt_CallbackBaton* baton = static_cast<ForeachExt_CallbackBaton*>(req->data);
  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) ForeachExt_callback_asyncPromisePolling);
  uv_async_send(&baton->req);
}

void GitStatus::ForeachExt_callback_asyncPromisePolling(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  ForeachExt_CallbackBaton* baton = static_cast<ForeachExt_CallbackBaton*>(req->data);
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
          baton->result = 0;
        }
       }
      else {
        baton->result = 0;
      }
     baton->done = true;
  }
  else {
    // promise was rejected
    GitStatus* instance = static_cast<GitStatus*>(baton->  payload  );
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
 * @param Number ignored
   * @param Repository repo
   * @param String path
     * @return Number  result    */
NAN_METHOD(GitStatus::ShouldIgnore) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number ignored is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

// start convert_from_v8 block
  int * from_ignored;
  *from_ignored = (int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[2]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
   int result = git_status_should_ignore(
from_ignored
,from_repo
,from_path
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitStatus::constructor_template;
 