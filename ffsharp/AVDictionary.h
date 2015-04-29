#pragma once

#include "wrapper/ffmpeg.h"

#include "AVErrorException.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Collections::Generic;

namespace ffsharp
{

	[Flags]
	public enum class AccessFlag
	{
		MatchCase = AV_DICT_MATCH_CASE,
		IgnoreSuffix = AV_DICT_IGNORE_SUFFIX,
		DontStrdupKey = AV_DICT_DONT_STRDUP_KEY,
		DontStrdupVal = AV_DICT_DONT_STRDUP_VAL,
		DontOverwrite = AV_DICT_DONT_OVERWRITE,
		Append = AV_DICT_APPEND
	};

	public ref class AVDictionaryEntry
	{
	private:
		ffmpeg::AVDictionaryEntry* p;

	internal:

		property ffmpeg::AVDictionaryEntry* Pointer
		{
			ffmpeg::AVDictionaryEntry* get()
			{
				return p;
			}
		}

	public:

		AVDictionaryEntry(ffmpeg::AVDictionaryEntry* p)
		{
			this->p = p;
		}

		property String^ Key
		{
			String^ get()
			{
				return gcnew String(p->key);
			}
		}

		property String^ Value
		{
			String^ get()
			{
				return gcnew String(p->value);
			}
		}

	};

	public ref class AVDictionaryIterator : IEnumerator < AVDictionaryEntry^ >
	{
	private:
		ffmpeg::AVDictionary* p;
		AVDictionaryEntry^ cur;

		AVDictionaryEntry^ Get(AVDictionaryEntry^ prev)
		{
			ffmpeg::AVDictionaryEntry* prevPtr = nullptr;
			if (prev != nullptr)
				prevPtr = prev->Pointer;
			auto entry = ffmpeg::av_dict_get(p, "", prevPtr, AV_DICT_IGNORE_SUFFIX);
			if (entry == nullptr)
				return nullptr;
			return gcnew AVDictionaryEntry(entry);
		}

	public:

		AVDictionaryIterator(ffmpeg::AVDictionary* p)
		{
			this->p = p;
			Reset();
		}

		property AVDictionaryEntry^ Current
		{
			virtual AVDictionaryEntry^ get()
			{
				return cur;
			}
		}

		virtual void Reset()
		{
			cur = Get(nullptr);
		}

		virtual bool MoveNext()
		{
			cur = Get(cur);
			return cur != nullptr;
		}

		property Object^ Current2
		{
			virtual Object^ get() = System::Collections::IEnumerator::Current::get
			{
				return cur;
			}
		}

		~AVDictionaryIterator()
		{

		}
	};

	public ref class AVDictionary : IEnumerable<AVDictionaryEntry^>
	{
	private:
		ffmpeg::AVDictionary* p;

	internal:

		property ffmpeg::AVDictionary* Pointer
		{
			ffmpeg::AVDictionary* get()
			{
				return p;
			}
		}

	public:

		AVDictionary()
			: AVDictionary(nullptr)
		{
			// avdictionary functions will implicitly create the dictionary
		}

		virtual IEnumerator<AVDictionaryEntry^>^ GetEnumerator()
		{
			return gcnew AVDictionaryIterator(p);
		}

		virtual System::Collections::IEnumerator^ GetEnumerator2() = System::Collections::IEnumerable::GetEnumerator
		{
			return GetEnumerator();
		}

		AVDictionaryEntry^ Get(String^ key)
		{
			return Get(key, nullptr, (AccessFlag)0);
		}

		AVDictionaryEntry^ Get(String^ key, AVDictionaryEntry^ prev)
		{
			return Get(key, prev, (AccessFlag) 0);
		}

		AVDictionaryEntry^ Get(String^ key, AVDictionaryEntry^ prev, AccessFlag flags)
		{
			IntPtr keyBuf = Marshal::StringToHGlobalAnsi(key);
			ffmpeg::AVDictionaryEntry* prevPtr = nullptr;
			if (prev != nullptr)
				prevPtr = prev->Pointer;
			try
			{
				ffmpeg::AVDictionaryEntry* entry = ffmpeg::av_dict_get(p, (const char*)keyBuf.ToPointer(), prevPtr, (int)flags);
				if (entry == nullptr)
					return nullptr;
				return gcnew AVDictionaryEntry(entry);
			}
			finally
			{
				if (keyBuf.ToPointer() != nullptr)
					Marshal::FreeHGlobal(keyBuf);
			}
		}

		void Delete(String^ key)
		{
			Set(key, nullptr);
		}

		void Set(String^ key, String^ value)
		{
			Set(key, value, (AccessFlag)0);
		}

		void Set(String^ key, String^ value, AccessFlag flags)
		{
			IntPtr keyBuf = Marshal::StringToHGlobalAnsi(key);
			IntPtr valueBuf = IntPtr::Zero;
			if (value != nullptr)
				valueBuf = Marshal::StringToHGlobalAnsi(value);
			try
			{
				pin_ptr<ffmpeg::AVDictionary*> pinnedDict = &p;
				int r = ffmpeg::av_dict_set(pinnedDict, (const char*)keyBuf.ToPointer(), (const char*)valueBuf.ToPointer(), (int)flags);
				if (r < 0)
					throw gcnew AVErrorException(r);
			}
			finally
			{
				if (keyBuf.ToPointer() != nullptr)
					Marshal::FreeHGlobal(keyBuf);
				if (valueBuf.ToPointer() != nullptr)
					Marshal::FreeHGlobal(valueBuf);
			}
		}

		AVDictionary(ffmpeg::AVDictionary* p)
		{
			this->p = p;
		}

		int Count()
		{
			return ffmpeg::av_dict_count(p);
		}

	};

}