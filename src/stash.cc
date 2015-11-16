// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/stash.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/repository.h"
  #include "../include/stash_apply_options.h"
  #include "../include/oid.h"
  #include "../include/signature.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

 
  void GitStash::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<Object> object = Nan::New<Object>();

        Nan::SetMethod(object, "apply", Apply);
         Nan::SetMethod(object, "applyInitOptions", ApplyInitOptions);
         Nan::SetMethod(object, "drop", Drop);
         Nan::SetMethod(object, "foreach", Foreach);
         Nan::SetMethod(object, "pop", Pop);
         Nan::SetMethod(object, "save", Save);
  
    Nan::Set(target, Nan::New<String>("Stash").ToLocalChecked(), object);
  }

 
/*
 * @param Repository repo
   * @param Number index
   * @param StashApplyOptions options
     */
NAN_METHOD(GitStash::Apply) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number index is required.");
  }

  if (info.Length() == 2 || !info[2]->IsObject()) {
    return Nan::ThrowError("StashApplyOptions options is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ApplyBaton* baton = new ApplyBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  size_t from_index;
  from_index = (size_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->index = from_index;
// start convert_from_v8 block
  const git_stash_apply_options * from_options;
  from_options = Nan::ObjectWrap::Unwrap<GitStashApplyOptions>(info[2]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->options = from_options;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  ApplyWorker *worker = new ApplyWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("index", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("options", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitStash::ApplyWorker::Execute() {
  int result = git_stash_apply(
baton->repo,baton->index,baton->options    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitStash::ApplyWorker::HandleOKCallback() {
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
      workerArguments.push(GetFromPersistent("index"));
      workerArguments.push(GetFromPersistent("options"));
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
        Local<v8::Object> err = Nan::Error("Method apply has thrown an error.")->ToObject();
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
 * @param StashApplyOptions opts
   * @param Number version
     * @return Number  result    */
NAN_METHOD(GitStash::ApplyInitOptions) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("StashApplyOptions opts is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number version is required.");
  }

// start convert_from_v8 block
  git_stash_apply_options * from_opts;
  from_opts = Nan::ObjectWrap::Unwrap<GitStashApplyOptions>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  unsigned int from_version;
  from_version = (unsigned int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_stash_apply_init_options(
from_opts
,from_version
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
 * @param Repository repo
   * @param Number index
     */
NAN_METHOD(GitStash::Drop) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number index is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  DropBaton* baton = new DropBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  size_t from_index;
  from_index = (size_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->index = from_index;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  DropWorker *worker = new DropWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("index", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitStash::DropWorker::Execute() {
  int result = git_stash_drop(
baton->repo,baton->index    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitStash::DropWorker::HandleOKCallback() {
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
      workerArguments.push(GetFromPersistent("index"));
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
        Local<v8::Object> err = Nan::Error("Method drop has thrown an error.")->ToObject();
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
   * @param StashCb callback
   * @param Void payload
     */
NAN_METHOD(GitStash::Foreach) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("StashCb callback is required.");
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

void GitStash::ForeachWorker::Execute() {
  int result = git_stash_foreach(
baton->repo,baton->callback,baton->payload    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitStash::ForeachWorker::HandleOKCallback() {
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


int GitStash::Foreach_callback_cppCallback (
    size_t index,     const char * message,     const git_oid * stash_id,     void * payload  ) {
  Foreach_CallbackBaton* baton = new Foreach_CallbackBaton();

    baton->index = index;
    baton->message = message;
    baton->stash_id = stash_id;
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

void GitStash::Foreach_callback_async(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  Foreach_CallbackBaton* baton = static_cast<Foreach_CallbackBaton*>(req->data);

     Nan::Callback* callback = ((Foreach_globalPayload*)baton->payload)->callback;
   
  Local<Value> argv[4] = {
          // HACK: NAN should really have an overload for Nan::New to support size_t
          Nan::New((unsigned int)baton->index),
            Nan::New(baton->message).ToLocalChecked(),
            GitOid::New((void *)baton->stash_id, false),
          // payload is null because we can use closure scope in javascript
        Nan::Undefined()
    };

  Nan::TryCatch tryCatch;
  Local<v8::Value> result = callback->Call(4, argv);

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

void GitStash::Foreach_callback_setupAsyncPromisePolling(uv_async_t* req) {
  Foreach_CallbackBaton* baton = static_cast<Foreach_CallbackBaton*>(req->data);
  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) Foreach_callback_asyncPromisePolling);
  uv_async_send(&baton->req);
}

void GitStash::Foreach_callback_asyncPromisePolling(uv_async_t* req, int status) {
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
    GitStash* instance = static_cast<GitStash*>(baton->   payload  );
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
   * @param Number index
   * @param StashApplyOptions options
     */
NAN_METHOD(GitStash::Pop) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number index is required.");
  }

  if (info.Length() == 2 || !info[2]->IsObject()) {
    return Nan::ThrowError("StashApplyOptions options is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  PopBaton* baton = new PopBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  size_t from_index;
  from_index = (size_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->index = from_index;
// start convert_from_v8 block
  const git_stash_apply_options * from_options;
  from_options = Nan::ObjectWrap::Unwrap<GitStashApplyOptions>(info[2]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->options = from_options;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  PopWorker *worker = new PopWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("index", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("options", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitStash::PopWorker::Execute() {
  int result = git_stash_pop(
baton->repo,baton->index,baton->options    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitStash::PopWorker::HandleOKCallback() {
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
      workerArguments.push(GetFromPersistent("index"));
      workerArguments.push(GetFromPersistent("options"));
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
        Local<v8::Object> err = Nan::Error("Method pop has thrown an error.")->ToObject();
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
   * @param Signature stasher
   * @param String message
   * @param Number flags
    * @param Oid callback
   */
NAN_METHOD(GitStash::Save) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("Signature stasher is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String message is required.");
  }

  if (info.Length() == 3 || !info[3]->IsNumber()) {
    return Nan::ThrowError("Number flags is required.");
  }

  if (info.Length() == 4 || !info[4]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  SaveBaton* baton = new SaveBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->out = (git_oid *)malloc(sizeof(git_oid ));
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const git_signature * from_stasher;
  from_stasher = Nan::ObjectWrap::Unwrap<GitSignature>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->stasher = from_stasher;
// start convert_from_v8 block
  const char * from_message;

  String::Utf8Value message(info[2]->ToString());
  from_message = (const char *) strdup(*message);
// end convert_from_v8 block
  baton->message = from_message;
// start convert_from_v8 block
  unsigned int from_flags;
  from_flags = (unsigned int)   info[3]->ToNumber()->Value();
// end convert_from_v8 block
  baton->flags = from_flags;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[4]));
  SaveWorker *worker = new SaveWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("stasher", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("message", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("flags", info[3]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitStash::SaveWorker::Execute() {
  int result = git_stash_save(
baton->out,baton->repo,baton->stasher,baton->message,baton->flags    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitStash::SaveWorker::HandleOKCallback() {
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
      workerArguments.push(GetFromPersistent("stasher"));
      workerArguments.push(GetFromPersistent("message"));
      workerArguments.push(GetFromPersistent("flags"));
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
        Local<v8::Object> err = Nan::Error("Method save has thrown an error.")->ToObject();
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

  free((void *)baton->message);

  delete baton;
}

      Nan::Persistent<Function> GitStash::constructor_template;
 