// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/submodule.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/repository.h"
  #include "../include/oid.h"
  #include "../include/buf.h"
  #include "../include/submodule_update_options.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitSubmodule::GitSubmodule(git_submodule *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitSubmodule::~GitSubmodule() {
      if (this->selfFreeing) {
        git_submodule_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                                                                                     }

  void GitSubmodule::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Submodule").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "addFinalize", AddFinalize);
             Nan::SetMethod(tpl, "addSetup", AddSetup);
            Nan::SetPrototypeMethod(tpl, "addToIndex", AddToIndex);
            Nan::SetPrototypeMethod(tpl, "branch", Branch);
            Nan::SetPrototypeMethod(tpl, "fetchRecurseSubmodules", FetchRecurseSubmodules);
            Nan::SetPrototypeMethod(tpl, "free", Free);
            Nan::SetPrototypeMethod(tpl, "headId", HeadId);
            Nan::SetPrototypeMethod(tpl, "ignore", Ignore);
            Nan::SetPrototypeMethod(tpl, "indexId", IndexId);
            Nan::SetPrototypeMethod(tpl, "init", Init);
             Nan::SetMethod(tpl, "lookup", Lookup);
            Nan::SetPrototypeMethod(tpl, "name", Name);
            Nan::SetPrototypeMethod(tpl, "open", Open);
            Nan::SetPrototypeMethod(tpl, "owner", Owner);
            Nan::SetPrototypeMethod(tpl, "path", Path);
            Nan::SetPrototypeMethod(tpl, "reload", Reload);
            Nan::SetPrototypeMethod(tpl, "repoInit", RepoInit);
             Nan::SetMethod(tpl, "resolveUrl", ResolveUrl);
             Nan::SetMethod(tpl, "setBranch", SetBranch);
             Nan::SetMethod(tpl, "setFetchRecurseSubmodules", SetFetchRecurseSubmodules);
             Nan::SetMethod(tpl, "setIgnore", SetIgnore);
             Nan::SetMethod(tpl, "setUpdate", SetUpdate);
             Nan::SetMethod(tpl, "setUrl", SetUrl);
            Nan::SetPrototypeMethod(tpl, "sync", Sync);
            Nan::SetPrototypeMethod(tpl, "update", Update);
             Nan::SetMethod(tpl, "updateInitOptions", UpdateInitOptions);
            Nan::SetPrototypeMethod(tpl, "updateStrategy", UpdateStrategy);
            Nan::SetPrototypeMethod(tpl, "url", Url);
            Nan::SetPrototypeMethod(tpl, "wdId", WdId);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Submodule").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitSubmodule::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitSubmodule cannot be instantiated.");
     }

    GitSubmodule* object = new GitSubmodule(static_cast<git_submodule *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitSubmodule::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitSubmodule::constructor_template), 2, argv).ToLocalChecked());
  }

  git_submodule *GitSubmodule::GetValue() {
    return this->raw;
  }

  git_submodule **GitSubmodule::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitSubmodule::ClearValue() {
    this->raw = NULL;
  }

  
/*
     * @return Number  result    */
NAN_METHOD(GitSubmodule::AddFinalize) {
  Nan::EscapableHandleScope scope;

   int result = git_submodule_add_finalize(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
  * @param Repository repo
   * @param String url
   * @param String path
   * @param Number use_gitlink
    * @param Submodule callback
   */
NAN_METHOD(GitSubmodule::AddSetup) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String url is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

  if (info.Length() == 3 || !info[3]->IsNumber()) {
    return Nan::ThrowError("Number use_gitlink is required.");
  }

  if (info.Length() == 4 || !info[4]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  AddSetupBaton* baton = new AddSetupBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_url;

  String::Utf8Value url(info[1]->ToString());
  from_url = (const char *) strdup(*url);
// end convert_from_v8 block
  baton->url = from_url;
// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[2]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
  baton->path = from_path;
// start convert_from_v8 block
  int from_use_gitlink;
  from_use_gitlink = (int)   info[3]->ToNumber()->Value();
// end convert_from_v8 block
  baton->use_gitlink = from_use_gitlink;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[4]));
  AddSetupWorker *worker = new AddSetupWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("url", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("path", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("use_gitlink", info[3]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitSubmodule::AddSetupWorker::Execute() {
  int result = git_submodule_add_setup(
&baton->out,baton->repo,baton->url,baton->path,baton->use_gitlink    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitSubmodule::AddSetupWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitSubmodule baton->out
       to = GitSubmodule::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("url"));
      workerArguments.push(GetFromPersistent("path"));
      workerArguments.push(GetFromPersistent("use_gitlink"));
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
        Local<v8::Object> err = Nan::Error("Method addSetup has thrown an error.")->ToObject();
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

  free((void *)baton->url);
  free((void *)baton->path);

  delete baton;
}

   
/*
   * @param Number write_index
     * @return Number  result    */
NAN_METHOD(GitSubmodule::AddToIndex) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number write_index is required.");
  }

// start convert_from_v8 block
  int from_write_index;
  from_write_index = (int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_submodule_add_to_index(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
,from_write_index
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return String  result    */
NAN_METHOD(GitSubmodule::Branch) {
  Nan::EscapableHandleScope scope;

   const char * result = git_submodule_branch(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
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
     * @return Number  result    */
NAN_METHOD(GitSubmodule::FetchRecurseSubmodules) {
  Nan::EscapableHandleScope scope;

   git_submodule_recurse_t result = git_submodule_fetch_recurse_submodules(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     */
NAN_METHOD(GitSubmodule::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue() != NULL) {
 git_submodule_free(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
  );

  Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->ClearValue();
}
   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
   
/*
     * @return Oid  result    */
NAN_METHOD(GitSubmodule::HeadId) {
  Nan::EscapableHandleScope scope;

   const git_oid * result = git_submodule_head_id(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
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
NAN_METHOD(GitSubmodule::Ignore) {
  Nan::EscapableHandleScope scope;

   git_submodule_ignore_t result = git_submodule_ignore(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Oid  result    */
NAN_METHOD(GitSubmodule::IndexId) {
  Nan::EscapableHandleScope scope;

   const git_oid * result = git_submodule_index_id(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
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
   * @param Number overwrite
     * @return Number  result    */
NAN_METHOD(GitSubmodule::Init) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number overwrite is required.");
  }

// start convert_from_v8 block
  int from_overwrite;
  from_overwrite = (int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_submodule_init(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
,from_overwrite
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
  * @param Repository repo
   * @param String name
    * @param Submodule callback
   */
NAN_METHOD(GitSubmodule::Lookup) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  LookupBaton* baton = new LookupBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[1]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
  baton->name = from_name;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  LookupWorker *worker = new LookupWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("name", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitSubmodule::LookupWorker::Execute() {
  int result = git_submodule_lookup(
&baton->out,baton->repo,baton->name    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitSubmodule::LookupWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitSubmodule baton->out
       to = GitSubmodule::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("name"));
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
        Local<v8::Object> err = Nan::Error("Method lookup has thrown an error.")->ToObject();
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

  free((void *)baton->name);

  delete baton;
}

   
/*
     * @return String  result    */
NAN_METHOD(GitSubmodule::Name) {
  Nan::EscapableHandleScope scope;

   const char * result = git_submodule_name(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
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
 * @param Repository repo
       * @return Number  result    */
NAN_METHOD(GitSubmodule::Open) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

// start convert_from_v8 block
  git_repository ** from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetRefValue();
// end convert_from_v8 block
   int result = git_submodule_open(
from_repo
,Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Repository  result    */
NAN_METHOD(GitSubmodule::Owner) {
  Nan::EscapableHandleScope scope;

   git_repository * result = git_submodule_owner(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
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
NAN_METHOD(GitSubmodule::Path) {
  Nan::EscapableHandleScope scope;

   const char * result = git_submodule_path(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
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
NAN_METHOD(GitSubmodule::Reload) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number force is required.");
  }

// start convert_from_v8 block
  int from_force;
  from_force = (int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_submodule_reload(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
,from_force
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
    * @param Number use_gitlink
    * @param Repository callback
   */
NAN_METHOD(GitSubmodule::RepoInit) {

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number use_gitlink is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  RepoInitBaton* baton = new RepoInitBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->sm = Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue();
// start convert_from_v8 block
  int from_use_gitlink;
  from_use_gitlink = (int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
  baton->use_gitlink = from_use_gitlink;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  RepoInitWorker *worker = new RepoInitWorker(baton, callback);
  worker->SaveToPersistent("sm", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("use_gitlink", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitSubmodule::RepoInitWorker::Execute() {
  int result = git_submodule_repo_init(
&baton->out,baton->sm,baton->use_gitlink    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitSubmodule::RepoInitWorker::HandleOKCallback() {
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
      workerArguments.push(GetFromPersistent("use_gitlink"));
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
        Local<v8::Object> err = Nan::Error("Method repoInit has thrown an error.")->ToObject();
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
   * @param String url
    * @param Buf callback
   */
NAN_METHOD(GitSubmodule::ResolveUrl) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String url is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ResolveUrlBaton* baton = new ResolveUrlBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

      baton->out = (git_buf *)malloc(sizeof(git_buf ));;
      baton->out->ptr = NULL;
      baton->out->size = baton->out->asize = 0;
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_url;

  String::Utf8Value url(info[1]->ToString());
  from_url = (const char *) strdup(*url);
// end convert_from_v8 block
  baton->url = from_url;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  ResolveUrlWorker *worker = new ResolveUrlWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("url", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitSubmodule::ResolveUrlWorker::Execute() {
  int result = git_submodule_resolve_url(
baton->out,baton->repo,baton->url    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitSubmodule::ResolveUrlWorker::HandleOKCallback() {
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
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("url"));
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
        Local<v8::Object> err = Nan::Error("Method resolveUrl has thrown an error.")->ToObject();
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
  free((void *)baton->url);

  delete baton;
}

   
/*
 * @param Repository repo
   * @param String name
   * @param String branch
     * @return Number  result    */
NAN_METHOD(GitSubmodule::SetBranch) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String branch is required.");
  }

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[1]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_branch;

  String::Utf8Value branch(info[2]->ToString());
  from_branch = (const char *) strdup(*branch);
// end convert_from_v8 block
   int result = git_submodule_set_branch(
from_repo
,from_name
,from_branch
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param Repository repo
   * @param String name
   * @param Number fetch_recurse_submodules
     * @return Number  result    */
NAN_METHOD(GitSubmodule::SetFetchRecurseSubmodules) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number fetch_recurse_submodules is required.");
  }

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[1]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
// start convert_from_v8 block
  git_submodule_recurse_t from_fetch_recurse_submodules;
  from_fetch_recurse_submodules = (git_submodule_recurse_t)  (int) info[2]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_submodule_set_fetch_recurse_submodules(
from_repo
,from_name
,from_fetch_recurse_submodules
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param Repository repo
   * @param String name
   * @param Number ignore
     * @return Number  result    */
NAN_METHOD(GitSubmodule::SetIgnore) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number ignore is required.");
  }

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[1]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
// start convert_from_v8 block
  git_submodule_ignore_t from_ignore;
  from_ignore = (git_submodule_ignore_t)  (int) info[2]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_submodule_set_ignore(
from_repo
,from_name
,from_ignore
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param Repository repo
   * @param String name
   * @param Number update
     * @return Number  result    */
NAN_METHOD(GitSubmodule::SetUpdate) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number update is required.");
  }

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[1]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
// start convert_from_v8 block
  git_submodule_update_t from_update;
  from_update = (git_submodule_update_t)  (int) info[2]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_submodule_set_update(
from_repo
,from_name
,from_update
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param Repository repo
   * @param String name
   * @param String url
     * @return Number  result    */
NAN_METHOD(GitSubmodule::SetUrl) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String url is required.");
  }

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[1]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_url;

  String::Utf8Value url(info[2]->ToString());
  from_url = (const char *) strdup(*url);
// end convert_from_v8 block
   int result = git_submodule_set_url(
from_repo
,from_name
,from_url
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitSubmodule::Sync) {
  Nan::EscapableHandleScope scope;

   int result = git_submodule_sync(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param Number init
   * @param SubmoduleUpdateOptions options
     * @return Number  result    */
NAN_METHOD(GitSubmodule::Update) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number init is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("SubmoduleUpdateOptions options is required.");
  }

// start convert_from_v8 block
  int from_init;
  from_init = (int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  git_submodule_update_options * from_options;
  from_options = Nan::ObjectWrap::Unwrap<GitSubmoduleUpdateOptions>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
   int result = git_submodule_update(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
,from_init
,from_options
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param SubmoduleUpdateOptions opts
   * @param Number version
     * @return Number  result    */
NAN_METHOD(GitSubmodule::UpdateInitOptions) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("SubmoduleUpdateOptions opts is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number version is required.");
  }

// start convert_from_v8 block
  git_submodule_update_options * from_opts;
  from_opts = Nan::ObjectWrap::Unwrap<GitSubmoduleUpdateOptions>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  unsigned int from_version;
  from_version = (unsigned int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_submodule_update_init_options(
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
     * @return Number  result    */
NAN_METHOD(GitSubmodule::UpdateStrategy) {
  Nan::EscapableHandleScope scope;

   git_submodule_update_t result = git_submodule_update_strategy(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return String  result    */
NAN_METHOD(GitSubmodule::Url) {
  Nan::EscapableHandleScope scope;

   const char * result = git_submodule_url(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
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
     * @return Oid  result    */
NAN_METHOD(GitSubmodule::WdId) {
  Nan::EscapableHandleScope scope;

   const git_oid * result = git_submodule_wd_id(
Nan::ObjectWrap::Unwrap<GitSubmodule>(info.This())->GetValue()
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
      Nan::Persistent<Function> GitSubmodule::constructor_template;
 