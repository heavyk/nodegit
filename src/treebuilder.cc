// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/treebuilder.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/tree_entry.h"
  #include "../include/oid.h"
  #include "../include/repository.h"
  #include "../include/tree.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitTreebuilder::GitTreebuilder(git_treebuilder *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitTreebuilder::~GitTreebuilder() {
      if (this->selfFreeing) {
        git_treebuilder_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                    }

  void GitTreebuilder::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Treebuilder").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "clear", Clear);
            Nan::SetPrototypeMethod(tpl, "entrycount", Entrycount);
            Nan::SetPrototypeMethod(tpl, "free", Free);
            Nan::SetPrototypeMethod(tpl, "get", Get);
            Nan::SetPrototypeMethod(tpl, "insert", Insert);
             Nan::SetMethod(tpl, "create", Create);
            Nan::SetPrototypeMethod(tpl, "remove", Remove);
            Nan::SetPrototypeMethod(tpl, "write", Write);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Treebuilder").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitTreebuilder::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitTreebuilder cannot be instantiated.");
     }

    GitTreebuilder* object = new GitTreebuilder(static_cast<git_treebuilder *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitTreebuilder::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitTreebuilder::constructor_template), 2, argv).ToLocalChecked());
  }

  git_treebuilder *GitTreebuilder::GetValue() {
    return this->raw;
  }

  git_treebuilder **GitTreebuilder::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitTreebuilder::ClearValue() {
    this->raw = NULL;
  }

  
/*
     */
NAN_METHOD(GitTreebuilder::Clear) {
  Nan::EscapableHandleScope scope;

 git_treebuilder_clear(
Nan::ObjectWrap::Unwrap<GitTreebuilder>(info.This())->GetValue()
  );

   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitTreebuilder::Entrycount) {
  Nan::EscapableHandleScope scope;

   unsigned int result = git_treebuilder_entrycount(
Nan::ObjectWrap::Unwrap<GitTreebuilder>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     */
NAN_METHOD(GitTreebuilder::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitTreebuilder>(info.This())->GetValue() != NULL) {
 git_treebuilder_free(
Nan::ObjectWrap::Unwrap<GitTreebuilder>(info.This())->GetValue()
  );

  Nan::ObjectWrap::Unwrap<GitTreebuilder>(info.This())->ClearValue();
}
   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
   
/*
   * @param String filename
     * @return TreeEntry  result    */
NAN_METHOD(GitTreebuilder::Get) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String filename is required.");
  }

// start convert_from_v8 block
  const char * from_filename;

  String::Utf8Value filename(info[0]->ToString());
  from_filename = (const char *) strdup(*filename);
// end convert_from_v8 block
   const git_tree_entry * result = git_treebuilder_get(
Nan::ObjectWrap::Unwrap<GitTreebuilder>(info.This())->GetValue()
,from_filename
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitTreeEntry result
       to = GitTreeEntry::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
    * @param String filename
   * @param Oid id
   * @param Number filemode
    * @param TreeEntry callback
   */
NAN_METHOD(GitTreebuilder::Insert) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String filename is required.");
  }

  if (info.Length() == 1
    || (!info[1]->IsObject() && !info[1]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number filemode is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  InsertBaton* baton = new InsertBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->bld = Nan::ObjectWrap::Unwrap<GitTreebuilder>(info.This())->GetValue();
// start convert_from_v8 block
  const char * from_filename;

  String::Utf8Value filename(info[0]->ToString());
  from_filename = (const char *) strdup(*filename);
// end convert_from_v8 block
  baton->filename = from_filename;
// start convert_from_v8 block
  const git_oid * from_id;
  if (info[1]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[1]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_id = oidOut;
  }
  else {
    from_id = Nan::ObjectWrap::Unwrap<GitOid>(info[1]->ToObject())->GetValue();
  }
// end convert_from_v8 block
  baton->id = from_id;
  baton->idNeedsFree = info[1]->IsString();
// start convert_from_v8 block
  git_filemode_t from_filemode;
  from_filemode = (git_filemode_t)  (int) info[2]->ToNumber()->Value();
// end convert_from_v8 block
  baton->filemode = from_filemode;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  InsertWorker *worker = new InsertWorker(baton, callback);
  worker->SaveToPersistent("bld", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("filename", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("id", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("filemode", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitTreebuilder::InsertWorker::Execute() {
  int result = git_treebuilder_insert(
&baton->out,baton->bld,baton->filename,baton->id,baton->filemode    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitTreebuilder::InsertWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitTreeEntry baton->out
       to = GitTreeEntry::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("filename"));
      workerArguments.push(GetFromPersistent("id"));
      workerArguments.push(GetFromPersistent("filemode"));
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
        Local<v8::Object> err = Nan::Error("Method insert has thrown an error.")->ToObject();
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

  free((void *)baton->filename);
  if (baton->idNeedsFree) {
    baton->idNeedsFree = false;
    free((void *)baton->id);
  }

  delete baton;
}

  
/*
  * @param Repository repo
   * @param Tree source
    * @param Treebuilder callback
   */
NAN_METHOD(GitTreebuilder::Create) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("Tree source is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  CreateBaton* baton = new CreateBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const git_tree * from_source;
  from_source = Nan::ObjectWrap::Unwrap<GitTree>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->source = from_source;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  CreateWorker *worker = new CreateWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("source", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitTreebuilder::CreateWorker::Execute() {
  int result = git_treebuilder_new(
&baton->out,baton->repo,baton->source    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitTreebuilder::CreateWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitTreebuilder baton->out
       to = GitTreebuilder::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("source"));
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
        Local<v8::Object> err = Nan::Error("Method create has thrown an error.")->ToObject();
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
   * @param String filename
     * @return Number  result    */
NAN_METHOD(GitTreebuilder::Remove) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String filename is required.");
  }

// start convert_from_v8 block
  const char * from_filename;

  String::Utf8Value filename(info[0]->ToString());
  from_filename = (const char *) strdup(*filename);
// end convert_from_v8 block
   int result = git_treebuilder_remove(
Nan::ObjectWrap::Unwrap<GitTreebuilder>(info.This())->GetValue()
,from_filename
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
      * @return Oid id    */
NAN_METHOD(GitTreebuilder::Write) {
  Nan::EscapableHandleScope scope;

  git_oid *id = (git_oid *)malloc(sizeof(git_oid));
   int result = git_treebuilder_write(
id
,Nan::ObjectWrap::Unwrap<GitTreebuilder>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (id != NULL) {
    // GitOid id
       to = GitOid::New((void *)id, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitTreebuilder::constructor_template;
 