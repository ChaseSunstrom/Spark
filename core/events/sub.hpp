#ifndef CORE_SUB_H
#define CORE_SUB_H

#include "../core.hpp"
#include "event.hpp"

namespace ac
{
	static uint64_t subscription_count = 0;

	__A_CORE_API__ enum class subscription_topic 
	{
		NONE = 0,
		WINDOW_EVENT,
		RENDERER_EVENT,
		APP_EVENT,
		INPUT_EVENT,
		EVERY_EVENT,
	};

	__A_CORE_API__ struct base_subscription
	{
		base_subscription(subscription_topic topic) : m_topic(topic), m_subscription_id(subscription_count++) {}

		virtual ~base_subscription() {}
		virtual void publish(subscription_topic topic, std::any value) = 0;
		virtual bool unsubscribe() = 0;

		uint64_t m_subscription_id;
		subscription_topic m_topic;
	};

	__A_CORE_API__ inline std::vector<std::shared_ptr<base_subscription>> subscriptions = std::vector<std::shared_ptr<base_subscription>>();

	template <typename T>
	__A_CORE_API__ struct subscription : base_subscription
	{
		static std::shared_ptr<subscription<T>> create(subscription_topic topic, std::function<void(std::shared_ptr<T>)> cb)
		{
			auto sub = std::shared_ptr<subscription<T>>(new subscription(topic, cb));
			subscriptions.push_back(std::static_pointer_cast<base_subscription>(sub));
			return sub;
		}

		void publish(subscription_topic topic, std::any value) override
		{
			if (topic == m_topic)
			{
				std::shared_ptr<T> casted_value = std::any_cast<std::shared_ptr<T>>(value);
				callback(casted_value);
			}
		}

		bool unsubscribe() override 
		{
			auto it = std::find_if(subscriptions.begin(), subscriptions.end(),
				[this](const std::shared_ptr<base_subscription>& sub) 
				{
					return sub->m_subscription_id == this->m_subscription_id;
				});

			if (it != subscriptions.end()) 
			{
				subscriptions.erase(it);
				return true; // Successfully unsubscribed
			}

			return false; // Subscription not found
		}

		std::function<void(std::shared_ptr<T>)> callback;

	private:
		// Make the constructor private to force usage of the factory method
		subscription(subscription_topic topic, std::function<void(std::shared_ptr<T>)> cb)
			: base_subscription(topic), callback(cb) { }
	};

	// Function to publish events to subscriptions of a specific topic.
	__A_CORE_API__ void publish_to_topic(subscription_topic topic, std::any value);
}

#endif