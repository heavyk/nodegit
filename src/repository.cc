// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/repository.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/config.h"
  #include "../include/buf.h"
  #include "../include/oid.h"
  #include "../include/reference.h"
  #include "../include/index.h"
  #include "../include/repository_init_options.h"
  #include "../include/odb.h"
  #include "../include/refdb.h"
  #include "../include/annotated_commit.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitRepository::GitRepository(git_repository *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitRepository::~GitRepository() {
      if (this->selfFreeing) {
        git_repository_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                                                                                                   }

  void GitRepository::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Repository").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "config", Config);
            Nan::SetPrototypeMethod(tpl, "configSnapshot", ConfigSnapshot);
            Nan::SetPrototypeMethod(tpl, "detachHead", DetachHead);
             Nan::SetMethod(tpl, "discover", Discover);
            Nan::SetPrototypeMethod(tpl, "fetchheadForeach", FetchheadForeach);
            Nan::SetPrototypeMethod(tpl, "free", Free);
            Nan::SetPrototypeMethod(tpl, "getNamespace", GetNamespace);
            Nan::SetPrototypeMethod(tpl, "head", Head);
            Nan::SetPrototypeMethod(tpl, "headDetached", HeadDetached);
            Nan::SetPrototypeMethod(tpl, "headUnborn", HeadUnborn);
            Nan::SetPrototypeMethod(tpl, "index", Index);
             Nan::SetMethod(tpl, "init", Init);
             Nan::SetMethod(tpl, "initExt", InitExt);
            Nan::SetPrototypeMethod(tpl, "isBare", IsBare);
            Nan::SetPrototypeMethod(tpl, "isEmpty", IsEmpty);
            Nan::SetPrototypeMethod(tpl, "isShallow", IsShallow);
            Nan::SetPrototypeMethod(tpl, "messageRemove", MessageRemove);
            Nan::SetPrototypeMethod(tpl, "odb", Odb);
             Nan::SetMethod(tpl, "open", Open);
             Nan::SetMethod(tpl, "openBare", OpenBare);
             Nan::SetMethod(tpl, "openExt", OpenExt);
            Nan::SetPrototypeMethod(tpl, "path", Path);
            Nan::SetPrototypeMethod(tpl, "refdb", Refdb);
            Nan::SetPrototypeMethod(tpl, "setHead", SetHead);
            Nan::SetPrototypeMethod(tpl, "setHeadDetached", SetHeadDetached);
            Nan::SetPrototypeMethod(tpl, "setHeadDetachedFromAnnotated", SetHeadDetachedFromAnnotated);
            Nan::SetPrototypeMethod(tpl, "setIdent", SetIdent);
            Nan::SetPrototypeMethod(tpl, "setNamespace", SetNamespace);
            Nan::SetPrototypeMethod(tpl, "setWorkdir", SetWorkdir);
            Nan::SetPrototypeMethod(tpl, "state", State);
            Nan::SetPrototypeMethod(tpl, "stateCleanup", StateCleanup);
            Nan::SetPrototypeMethod(tpl, "workdir", Workdir);
             Nan::SetMethod(tpl, "wrapOdb", WrapOdb);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Repository").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitRepository::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitRepository cannot be instantiated.");
     }

    GitRepository* object = new GitRepository(static_cast<git_repository *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitRepository::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitRepository::constructor_template), 2, argv).ToLocalChecked());
  }

  git_repository *GitRepository::GetValue() {
    return this->raw;
  }

  git_repository **GitRepository::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitRepository::ClearValue() {
    this->raw = NULL;
  }

 
/*
     * @param Config callback
   */
NAN_METHOD(GitRepository::Config) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ConfigBaton* baton = new ConfigBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->repo = Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[0]));
  ConfigWorker *worker = new ConfigWorker(baton, callback);
  worker->SaveToPersistent("repo", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRepository::ConfigWorker::Execute() {
  int result = git_repository_config(
&baton->out,baton->repo    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRepository::ConfigWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitConfig baton->out
       to = GitConfig::New((void *)baton->out, false);
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
        Local<v8::Object> err = Nan::Error("Method config has thrown an error.")->ToObject();
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
     * @param Config callback
   */
NAN_METHOD(GitRepository::ConfigSnapshot) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ConfigSnapshotBaton* baton = new ConfigSnapshotBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->repo = Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[0]));
  ConfigSnapshotWorker *worker = new ConfigSnapshotWorker(baton, callback);
  worker->SaveToPersistent("repo", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRepository::ConfigSnapshotWorker::Execute() {
  int result = git_repository_config_snapshot(
&baton->out,baton->repo    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRepository::ConfigSnapshotWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitConfig baton->out
       to = GitConfig::New((void *)baton->out, false);
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
        Local<v8::Object> err = Nan::Error("Method configSnapshot has thrown an error.")->ToObject();
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
     * @return Number  result    */
NAN_METHOD(GitRepository::DetachHead) {
  Nan::EscapableHandleScope scope;

   int result = git_repository_detach_head(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
  * @param String start_path
   * @param Number across_fs
   * @param String ceiling_dirs
    * @param Buf callback
   */
NAN_METHOD(GitRepository::Discover) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String start_path is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number across_fs is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String ceiling_dirs is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  DiscoverBaton* baton = new DiscoverBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

      baton->out = (git_buf *)malloc(sizeof(git_buf ));;
      baton->out->ptr = NULL;
      baton->out->size = baton->out->asize = 0;
// start convert_from_v8 block
  const char * from_start_path;

  String::Utf8Value start_path(info[0]->ToString());
  from_start_path = (const char *) strdup(*start_path);
// end convert_from_v8 block
  baton->start_path = from_start_path;
// start convert_from_v8 block
  int from_across_fs;
  from_across_fs = (int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->across_fs = from_across_fs;
// start convert_from_v8 block
  const char * from_ceiling_dirs;

  String::Utf8Value ceiling_dirs(info[2]->ToString());
  from_ceiling_dirs = (const char *) strdup(*ceiling_dirs);
// end convert_from_v8 block
  baton->ceiling_dirs = from_ceiling_dirs;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  DiscoverWorker *worker = new DiscoverWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("start_path", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("across_fs", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("ceiling_dirs", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRepository::DiscoverWorker::Execute() {
  int result = git_repository_discover(
baton->out,baton->start_path,baton->across_fs,baton->ceiling_dirs    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRepository::DiscoverWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  if (baton->out) {
    to = Nan::New<String>(baton->out->ptr, baton->out->size).ToLocalChecked();
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
      workerArguments.push(GetFromPersistent("start_path"));
      workerArguments.push(GetFromPersistent("across_fs"));
      workerArguments.push(GetFromPersistent("ceiling_dirs"));
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
        Local<v8::Object> err = Nan::Error("Method discover has thrown an error.")->ToObject();
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

  git_buf_free(baton->out);
  free((void *)baton->out);
  free((void *)baton->start_path);
  free((void *)baton->ceiling_dirs);

  delete baton;
}

  
/*
   * @param RepositoryFetchheadForeachCb callback
   * @param Void payload
     */
NAN_METHOD(GitRepository::FetchheadForeach) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("RepositoryFetchheadForeachCb callback is required.");
  }
  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  FetchheadForeachBaton* baton = new FetchheadForeachBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  FetchheadForeach_globalPayload* globalPayload = new FetchheadForeach_globalPayload;
  baton->repo = Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue();
  if (!info[0]->IsFunction()) {
    baton->callback = NULL;
    globalPayload->callback = NULL;
  }
  else {
    baton->callback = FetchheadForeach_callback_cppCallback;
    globalPayload->callback = new Nan::Callback(info[0].As<Function>());
  }
  baton->payload = globalPayload;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  FetchheadForeachWorker *worker = new FetchheadForeachWorker(baton, callback);
  worker->SaveToPersistent("repo", info.This());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("payload", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRepository::FetchheadForeachWorker::Execute() {
  int result = git_repository_fetchhead_foreach(
baton->repo,baton->callback,baton->payload    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRepository::FetchheadForeachWorker::HandleOKCallback() {
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
        Local<v8::Object> err = Nan::Error("Method fetchheadForeach has thrown an error.")->ToObject();
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

  delete (FetchheadForeach_globalPayload*)baton->payload;

  delete baton;
}


int GitRepository::FetchheadForeach_callback_cppCallback (
    const char * refname,     const char * remote_url,     const git_oid * oid,     unsigned int is_merge,     void * payload  ) {
  FetchheadForeach_CallbackBaton* baton = new FetchheadForeach_CallbackBaton();

    baton->refname = refname;
    baton->remote_url = remote_url;
    baton->oid = oid;
    baton->is_merge = is_merge;
    baton->payload = payload;
 
  baton->result = 0;
  baton->req.data = baton;
  baton->done = false;

  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) FetchheadForeach_callback_async);
  uv_async_send(&baton->req);

  while(!baton->done) {
    sleep_for_ms(1);
  }

  
  return baton->result;
}

void GitRepository::FetchheadForeach_callback_async(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  FetchheadForeach_CallbackBaton* baton = static_cast<FetchheadForeach_CallbackBaton*>(req->data);

      Nan::Callback* callback = ((FetchheadForeach_globalPayload*)baton->payload)->callback;
   
  Local<Value> argv[5] = {
          Nan::New(baton->refname).ToLocalChecked(),
            Nan::New(baton->remote_url).ToLocalChecked(),
            GitOid::New((void *)baton->oid, false),
             Nan::New(baton->is_merge),
          // payload is null because we can use closure scope in javascript
        Nan::Undefined()
    };

  Nan::TryCatch tryCatch;
  Local<v8::Value> result = callback->Call(5, argv);

  if (result->IsObject() && Nan::Has(result->ToObject(), Nan::New("then").ToLocalChecked()).FromJust()) {
    Local<v8::Value> thenProp = Nan::Get(result->ToObject(), Nan::New("then").ToLocalChecked()).ToLocalChecked();

    if (thenProp->IsFunction()) {
      // we can be reasonbly certain that the result is a promise
      Local<Object> promise = result->ToObject();

      baton->promise.Reset(promise);

      uv_close((uv_handle_t*) &baton->req, (uv_close_cb) FetchheadForeach_callback_setupAsyncPromisePolling);
      return;
    }
  }

    if (result.IsEmpty() || result->IsNativeError()) {
      baton->result = 1;
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

void GitRepository::FetchheadForeach_callback_setupAsyncPromisePolling(uv_async_t* req) {
  FetchheadForeach_CallbackBaton* baton = static_cast<FetchheadForeach_CallbackBaton*>(req->data);
  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) FetchheadForeach_callback_asyncPromisePolling);
  uv_async_send(&baton->req);
}

void GitRepository::FetchheadForeach_callback_asyncPromisePolling(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  FetchheadForeach_CallbackBaton* baton = static_cast<FetchheadForeach_CallbackBaton*>(req->data);
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
        baton->result = 1;
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
    GitRepository* instance = static_cast<GitRepository*>(baton->    payload  );
    Local<v8::Object> parent = instance->handle();
    Nan::Callback* reasonFn = new Nan::Callback(Nan::Get(promise, Nan::New("reason").ToLocalChecked()).ToLocalChecked().As<Function>());
    Local<v8::Value> reason = reasonFn->Call(promise, 0, argv);
    parent->SetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked(), reason);

    baton->result = 1;
    baton->done = true;
  }

  uv_close((uv_handle_t*) &baton->req, NULL);
}
   
/*
     */
NAN_METHOD(GitRepository::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue() != NULL) {
 git_repository_free(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
  );

  Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->ClearValue();
}
   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
   
/*
     * @return String  result    */
NAN_METHOD(GitRepository::GetNamespace) {
  Nan::EscapableHandleScope scope;

   const char * result = git_repository_get_namespace(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
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
     * @param Reference callback
   */
NAN_METHOD(GitRepository::Head) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  HeadBaton* baton = new HeadBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->repo = Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[0]));
  HeadWorker *worker = new HeadWorker(baton, callback);
  worker->SaveToPersistent("repo", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRepository::HeadWorker::Execute() {
  int result = git_repository_head(
&baton->out,baton->repo    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRepository::HeadWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRefs baton->out
       to = GitRefs::New((void *)baton->out, false);
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
        Local<v8::Object> err = Nan::Error("Method head has thrown an error.")->ToObject();
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
     * @return Number  result    */
NAN_METHOD(GitRepository::HeadDetached) {
  Nan::EscapableHandleScope scope;

   int result = git_repository_head_detached(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitRepository::HeadUnborn) {
  Nan::EscapableHandleScope scope;

   int result = git_repository_head_unborn(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
     * @param Index callback
   */
NAN_METHOD(GitRepository::Index) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  IndexBaton* baton = new IndexBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->repo = Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[0]));
  IndexWorker *worker = new IndexWorker(baton, callback);
  worker->SaveToPersistent("repo", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRepository::IndexWorker::Execute() {
  int result = git_repository_index(
&baton->out,baton->repo    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRepository::IndexWorker::HandleOKCallback() {
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
        Local<v8::Object> err = Nan::Error("Method index has thrown an error.")->ToObject();
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
  * @param String path
   * @param Number is_bare
    * @param Repository callback
   */
NAN_METHOD(GitRepository::Init) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number is_bare is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  InitBaton* baton = new InitBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[0]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
  baton->path = from_path;
// start convert_from_v8 block
  unsigned int from_is_bare;
  from_is_bare = (unsigned int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->is_bare = from_is_bare;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  InitWorker *worker = new InitWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("path", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("is_bare", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRepository::InitWorker::Execute() {
  int result = git_repository_init(
&baton->out,baton->path,baton->is_bare    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRepository::InitWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRepository baton->out
       to = GitRepository::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("path"));
      workerArguments.push(GetFromPersistent("is_bare"));
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
        Local<v8::Object> err = Nan::Error("Method init has thrown an error.")->ToObject();
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
  * @param String repo_path
   * @param RepositoryInitOptions opts
    * @param Repository callback
   */
NAN_METHOD(GitRepository::InitExt) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String repo_path is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("RepositoryInitOptions opts is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  InitExtBaton* baton = new InitExtBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_repo_path;

  String::Utf8Value repo_path(info[0]->ToString());
  from_repo_path = (const char *) strdup(*repo_path);
// end convert_from_v8 block
  baton->repo_path = from_repo_path;
// start convert_from_v8 block
  git_repository_init_options * from_opts;
  from_opts = Nan::ObjectWrap::Unwrap<GitRepositoryInitOptions>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->opts = from_opts;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  InitExtWorker *worker = new InitExtWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo_path", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("opts", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRepository::InitExtWorker::Execute() {
  int result = git_repository_init_ext(
&baton->out,baton->repo_path,baton->opts    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRepository::InitExtWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRepository baton->out
       to = GitRepository::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("repo_path"));
      workerArguments.push(GetFromPersistent("opts"));
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
        Local<v8::Object> err = Nan::Error("Method initExt has thrown an error.")->ToObject();
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

  free((void *)baton->repo_path);

  delete baton;
}

   
/*
     * @return Number  result    */
NAN_METHOD(GitRepository::IsBare) {
  Nan::EscapableHandleScope scope;

   int result = git_repository_is_bare(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitRepository::IsEmpty) {
  Nan::EscapableHandleScope scope;

   int result = git_repository_is_empty(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitRepository::IsShallow) {
  Nan::EscapableHandleScope scope;

   int result = git_repository_is_shallow(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitRepository::MessageRemove) {
  Nan::EscapableHandleScope scope;

   int result = git_repository_message_remove(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
     * @param Odb callback
   */
NAN_METHOD(GitRepository::Odb) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  OdbBaton* baton = new OdbBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->repo = Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[0]));
  OdbWorker *worker = new OdbWorker(baton, callback);
  worker->SaveToPersistent("repo", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRepository::OdbWorker::Execute() {
  int result = git_repository_odb(
&baton->out,baton->repo    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRepository::OdbWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitOdb baton->out
       to = GitOdb::New((void *)baton->out, false);
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
        Local<v8::Object> err = Nan::Error("Method odb has thrown an error.")->ToObject();
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
  * @param String path
    * @param Repository callback
   */
NAN_METHOD(GitRepository::Open) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  OpenBaton* baton = new OpenBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[0]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
  baton->path = from_path;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  OpenWorker *worker = new OpenWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("path", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRepository::OpenWorker::Execute() {
  int result = git_repository_open(
&baton->out,baton->path    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRepository::OpenWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRepository baton->out
       to = GitRepository::New((void *)baton->out, false);
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

  free((void *)baton->path);

  delete baton;
}

  
/*
  * @param String bare_path
    * @param Repository callback
   */
NAN_METHOD(GitRepository::OpenBare) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String bare_path is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  OpenBareBaton* baton = new OpenBareBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_bare_path;

  String::Utf8Value bare_path(info[0]->ToString());
  from_bare_path = (const char *) strdup(*bare_path);
// end convert_from_v8 block
  baton->bare_path = from_bare_path;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  OpenBareWorker *worker = new OpenBareWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("bare_path", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRepository::OpenBareWorker::Execute() {
  int result = git_repository_open_bare(
&baton->out,baton->bare_path    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRepository::OpenBareWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRepository baton->out
       to = GitRepository::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("bare_path"));
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
        Local<v8::Object> err = Nan::Error("Method openBare has thrown an error.")->ToObject();
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

  free((void *)baton->bare_path);

  delete baton;
}

  
/*
  * @param String path
   * @param Number flags
   * @param String ceiling_dirs
    * @param Repository callback
   */
NAN_METHOD(GitRepository::OpenExt) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number flags is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String ceiling_dirs is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  OpenExtBaton* baton = new OpenExtBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[0]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
  baton->path = from_path;
// start convert_from_v8 block
  unsigned int from_flags;
  from_flags = (unsigned int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->flags = from_flags;
// start convert_from_v8 block
  const char * from_ceiling_dirs;

  String::Utf8Value ceiling_dirs(info[2]->ToString());
  from_ceiling_dirs = (const char *) strdup(*ceiling_dirs);
// end convert_from_v8 block
  baton->ceiling_dirs = from_ceiling_dirs;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  OpenExtWorker *worker = new OpenExtWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("path", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("flags", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("ceiling_dirs", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRepository::OpenExtWorker::Execute() {
  int result = git_repository_open_ext(
&baton->out,baton->path,baton->flags,baton->ceiling_dirs    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRepository::OpenExtWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRepository baton->out
       to = GitRepository::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("path"));
      workerArguments.push(GetFromPersistent("flags"));
      workerArguments.push(GetFromPersistent("ceiling_dirs"));
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
        Local<v8::Object> err = Nan::Error("Method openExt has thrown an error.")->ToObject();
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
  free((void *)baton->ceiling_dirs);

  delete baton;
}

   
/*
     * @return String  result    */
NAN_METHOD(GitRepository::Path) {
  Nan::EscapableHandleScope scope;

   const char * result = git_repository_path(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
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
     * @param Refdb callback
   */
NAN_METHOD(GitRepository::Refdb) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  RefdbBaton* baton = new RefdbBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->repo = Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[0]));
  RefdbWorker *worker = new RefdbWorker(baton, callback);
  worker->SaveToPersistent("repo", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRepository::RefdbWorker::Execute() {
  int result = git_repository_refdb(
&baton->out,baton->repo    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRepository::RefdbWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRefdb baton->out
       to = GitRefdb::New((void *)baton->out, false);
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
        Local<v8::Object> err = Nan::Error("Method refdb has thrown an error.")->ToObject();
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
   * @param String refname
     */
NAN_METHOD(GitRepository::SetHead) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String refname is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  SetHeadBaton* baton = new SetHeadBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->repo = Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue();
// start convert_from_v8 block
  const char * from_refname;

  String::Utf8Value refname(info[0]->ToString());
  from_refname = (const char *) strdup(*refname);
// end convert_from_v8 block
  baton->refname = from_refname;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  SetHeadWorker *worker = new SetHeadWorker(baton, callback);
  worker->SaveToPersistent("repo", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("refname", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRepository::SetHeadWorker::Execute() {
  int result = git_repository_set_head(
baton->repo,baton->refname    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRepository::SetHeadWorker::HandleOKCallback() {
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
      workerArguments.push(GetFromPersistent("refname"));
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
        Local<v8::Object> err = Nan::Error("Method setHead has thrown an error.")->ToObject();
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

  free((void *)baton->refname);

  delete baton;
}

   
/*
   * @param Oid commitish
     * @return Number  result    */
NAN_METHOD(GitRepository::SetHeadDetached) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0
    || (!info[0]->IsObject() && !info[0]->IsString())) {
    return Nan::ThrowError("Oid commitish is required.");
  }
// start convert_from_v8 block
  const git_oid * from_commitish;
  if (info[0]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[0]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_commitish = oidOut;
  }
  else {
    from_commitish = Nan::ObjectWrap::Unwrap<GitOid>(info[0]->ToObject())->GetValue();
  }
// end convert_from_v8 block
   int result = git_repository_set_head_detached(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
,from_commitish
  );

   if (info[0]->IsString()) {
    free((void *)from_commitish);
  }

  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param AnnotatedCommit commitish
     * @return Number  result    */
NAN_METHOD(GitRepository::SetHeadDetachedFromAnnotated) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("AnnotatedCommit commitish is required.");
  }

// start convert_from_v8 block
  const git_annotated_commit * from_commitish;
  from_commitish = Nan::ObjectWrap::Unwrap<GitAnnotatedCommit>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   int result = git_repository_set_head_detached_from_annotated(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
,from_commitish
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param String name
   * @param String email
     * @return Number  result    */
NAN_METHOD(GitRepository::SetIdent) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String email is required.");
  }

// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[0]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_email;

  String::Utf8Value email(info[1]->ToString());
  from_email = (const char *) strdup(*email);
// end convert_from_v8 block
   int result = git_repository_set_ident(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
,from_name
,from_email
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param String nmspace
     * @return Number  result    */
NAN_METHOD(GitRepository::SetNamespace) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String nmspace is required.");
  }

// start convert_from_v8 block
  const char * from_nmspace;

  String::Utf8Value nmspace(info[0]->ToString());
  from_nmspace = (const char *) strdup(*nmspace);
// end convert_from_v8 block
   int result = git_repository_set_namespace(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
,from_nmspace
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param String workdir
   * @param Number update_gitlink
     * @return Number  result    */
NAN_METHOD(GitRepository::SetWorkdir) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String workdir is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number update_gitlink is required.");
  }

// start convert_from_v8 block
  const char * from_workdir;

  String::Utf8Value workdir(info[0]->ToString());
  from_workdir = (const char *) strdup(*workdir);
// end convert_from_v8 block
// start convert_from_v8 block
  int from_update_gitlink;
  from_update_gitlink = (int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_repository_set_workdir(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
,from_workdir
,from_update_gitlink
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitRepository::State) {
  Nan::EscapableHandleScope scope;

   int result = git_repository_state(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitRepository::StateCleanup) {
  Nan::EscapableHandleScope scope;

   int result = git_repository_state_cleanup(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return String  result    */
NAN_METHOD(GitRepository::Workdir) {
  Nan::EscapableHandleScope scope;

   const char * result = git_repository_workdir(
Nan::ObjectWrap::Unwrap<GitRepository>(info.This())->GetValue()
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
  * @param Odb odb
    * @param Repository callback
   */
NAN_METHOD(GitRepository::WrapOdb) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Odb odb is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  WrapOdbBaton* baton = new WrapOdbBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_odb * from_odb;
  from_odb = Nan::ObjectWrap::Unwrap<GitOdb>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->odb = from_odb;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  WrapOdbWorker *worker = new WrapOdbWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("odb", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRepository::WrapOdbWorker::Execute() {
  int result = git_repository_wrap_odb(
&baton->out,baton->odb    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRepository::WrapOdbWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRepository baton->out
       to = GitRepository::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("odb"));
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
        Local<v8::Object> err = Nan::Error("Method wrapOdb has thrown an error.")->ToObject();
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

      Nan::Persistent<Function> GitRepository::constructor_template;
 