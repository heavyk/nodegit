// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/blob.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/wrapper.h"
  #include "node_buffer.h"
  #include "../include/oid.h"
  #include "../include/repository.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitBlob::GitBlob(git_blob *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitBlob::~GitBlob() {
      if (this->selfFreeing) {
        git_blob_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                }

  void GitBlob::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Blob").ToLocalChecked());

           Nan::SetMethod(tpl, "createFromBuffer", CreateFrombuffer);
             Nan::SetMethod(tpl, "createFromDisk", CreateFromdisk);
             Nan::SetMethod(tpl, "createFromWorkdir", CreateFromworkdir);
            Nan::SetPrototypeMethod(tpl, "free", Free);
            Nan::SetPrototypeMethod(tpl, "id", Id);
            Nan::SetPrototypeMethod(tpl, "isBinary", IsBinary);
             Nan::SetMethod(tpl, "lookup", Lookup);
             Nan::SetMethod(tpl, "lookupPrefix", LookupPrefix);
            Nan::SetPrototypeMethod(tpl, "owner", Owner);
            Nan::SetPrototypeMethod(tpl, "rawcontent", Rawcontent);
            Nan::SetPrototypeMethod(tpl, "rawsize", Rawsize);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Blob").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitBlob::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitBlob cannot be instantiated.");
     }

    GitBlob* object = new GitBlob(static_cast<git_blob *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitBlob::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitBlob::constructor_template), 2, argv).ToLocalChecked());
  }

  git_blob *GitBlob::GetValue() {
    return this->raw;
  }

  git_blob **GitBlob::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitBlob::ClearValue() {
    this->raw = NULL;
  }

  
/*
  * @param Repository repo
   * @param Buffer buffer
   * @param Number len
     * @return Oid id    */
NAN_METHOD(GitBlob::CreateFrombuffer) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("Buffer buffer is required.");
  }

  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number len is required.");
  }

  git_oid *id = (git_oid *)malloc(sizeof(git_oid));
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const void * from_buffer;

  from_buffer = Buffer::Data(info[1]->ToObject());
// end convert_from_v8 block
// start convert_from_v8 block
  size_t from_len;
  from_len = (size_t)   info[2]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_blob_create_frombuffer(
id
,from_repo
,from_buffer
,from_len
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
   
/*
 * @param Oid id
   * @param Repository repo
   * @param String path
     * @return Number  result    */
NAN_METHOD(GitBlob::CreateFromdisk) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0
    || (!info[0]->IsObject() && !info[0]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

// start convert_from_v8 block
  git_oid * from_id;
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

    from_id = oidOut;
  }
  else {
    from_id = Nan::ObjectWrap::Unwrap<GitOid>(info[0]->ToObject())->GetValue();
  }
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
   int result = git_blob_create_fromdisk(
from_id
,from_repo
,from_path
  );

   if (info[0]->IsString()) {
    free((void *)from_id);
  }

  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param Oid id
   * @param Repository repo
   * @param String relative_path
     * @return Number  result    */
NAN_METHOD(GitBlob::CreateFromworkdir) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0
    || (!info[0]->IsObject() && !info[0]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String relative_path is required.");
  }

// start convert_from_v8 block
  git_oid * from_id;
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

    from_id = oidOut;
  }
  else {
    from_id = Nan::ObjectWrap::Unwrap<GitOid>(info[0]->ToObject())->GetValue();
  }
// end convert_from_v8 block
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_relative_path;

  String::Utf8Value relative_path(info[2]->ToString());
  from_relative_path = (const char *) strdup(*relative_path);
// end convert_from_v8 block
   int result = git_blob_create_fromworkdir(
from_id
,from_repo
,from_relative_path
  );

   if (info[0]->IsString()) {
    free((void *)from_id);
  }

  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     */
NAN_METHOD(GitBlob::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitBlob>(info.This())->GetValue() != NULL) {
 git_blob_free(
Nan::ObjectWrap::Unwrap<GitBlob>(info.This())->GetValue()
  );

  Nan::ObjectWrap::Unwrap<GitBlob>(info.This())->ClearValue();
}
   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
   
/*
     * @return Oid  result    */
NAN_METHOD(GitBlob::Id) {
  Nan::EscapableHandleScope scope;

   const git_oid * result = git_blob_id(
Nan::ObjectWrap::Unwrap<GitBlob>(info.This())->GetValue()
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
NAN_METHOD(GitBlob::IsBinary) {
  Nan::EscapableHandleScope scope;

   int result = git_blob_is_binary(
Nan::ObjectWrap::Unwrap<GitBlob>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
  * @param Repository repo
   * @param Oid id
    * @param Blob callback
   */
NAN_METHOD(GitBlob::Lookup) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1
    || (!info[1]->IsObject() && !info[1]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
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

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  LookupWorker *worker = new LookupWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("id", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitBlob::LookupWorker::Execute() {
  int result = git_blob_lookup(
&baton->blob,baton->repo,baton->id    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitBlob::LookupWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->blob != NULL) {
    // GitBlob baton->blob
       to = GitBlob::New((void *)baton->blob, false);
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
      workerArguments.push(GetFromPersistent("id"));
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

  if (baton->idNeedsFree) {
    baton->idNeedsFree = false;
    free((void *)baton->id);
  }

  delete baton;
}

  
/*
  * @param Repository repo
   * @param Oid id
   * @param Number len
    * @param Blob callback
   */
NAN_METHOD(GitBlob::LookupPrefix) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1
    || (!info[1]->IsObject() && !info[1]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number len is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  LookupPrefixBaton* baton = new LookupPrefixBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
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
  size_t from_len;
  from_len = (size_t)   info[2]->ToNumber()->Value();
// end convert_from_v8 block
  baton->len = from_len;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  LookupPrefixWorker *worker = new LookupPrefixWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("id", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("len", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitBlob::LookupPrefixWorker::Execute() {
  int result = git_blob_lookup_prefix(
&baton->blob,baton->repo,baton->id,baton->len    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitBlob::LookupPrefixWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->blob != NULL) {
    // GitBlob baton->blob
       to = GitBlob::New((void *)baton->blob, false);
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
      workerArguments.push(GetFromPersistent("id"));
      workerArguments.push(GetFromPersistent("len"));
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
        Local<v8::Object> err = Nan::Error("Method lookupPrefix has thrown an error.")->ToObject();
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

  if (baton->idNeedsFree) {
    baton->idNeedsFree = false;
    free((void *)baton->id);
  }

  delete baton;
}

   
/*
     * @return Repository  result    */
NAN_METHOD(GitBlob::Owner) {
  Nan::EscapableHandleScope scope;

   git_repository * result = git_blob_owner(
Nan::ObjectWrap::Unwrap<GitBlob>(info.This())->GetValue()
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
     * @return Buffer  result    */
NAN_METHOD(GitBlob::Rawcontent) {
  Nan::EscapableHandleScope scope;

   const void * result = git_blob_rawcontent(
Nan::ObjectWrap::Unwrap<GitBlob>(info.This())->GetValue()
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // Wrapper result
      to = Wrapper::New((void *)result);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitBlob::Rawsize) {
  Nan::EscapableHandleScope scope;

   git_off_t result = git_blob_rawsize(
Nan::ObjectWrap::Unwrap<GitBlob>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitBlob::constructor_template;
 