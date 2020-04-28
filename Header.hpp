#pragma once

namespace claudiu
{
	template <typename T>
	class Queue
	{
	public:

		inline void InitQueue()
		{
			first = std::make_shared<Item>();
		}

		inline void Front()
		{
			if (isEmpty())
				std::cout << "Queue empty!" << std::endl;
			else
				std::cout << GetValue() << std::endl;
		}

		void Pop()
		{
			if (isEmpty())
			{
				std::cout << "Queue empty!" << std::endl;
			}
			else
			{
				std::cout << first->GetValue() << " ";
				first = first->GetLink();
			}

		}

		inline bool isEmpty()
		{
			if (!this->first) return true;
			return false;
		}

		void Push() { };
		template <typename ...args>
		void Push(T value, args... var)
		{
			if (isEmpty())
			{
				InitQueue();
				first->SetValue(value);
			}
			else
			{
				if (first->GetLink() == nullptr)
				{
					std::shared_ptr<Item> element = std::make_shared<Item>();
					element->SetValue(value);
					element->SetLink(nullptr);

					first->SetLink(element);
					rear = element;
				}
				else
				{
					std::shared_ptr<Item> element = std::make_shared<Item>();
					element->SetValue(value);
					element->SetLink(nullptr);

					rear->SetLink(element);

					rear = element;
				}
				
			}
			Push(var...);
		}

		~Queue();

	private:

		struct Item
		{
		private:
			T value;
			std::shared_ptr<Item> link;
		public:
			inline void SetValue(T v)
			{
				value = v;
			}
			inline T GetValue()
			{
				return value;
			}
			inline std::shared_ptr<Item> GetLink()
			{
				return link;
			}
			inline void SetLink(std::shared_ptr<Item> l)
			{
				link = l;
			}
		};

		std::shared_ptr<Item> first;
		std::shared_ptr<Item> rear;

		inline T GetValue()
		{
			return first->GetValue();
		}
	};

	template<typename T>
	inline Queue<T>::~Queue()
	{

	}

}
