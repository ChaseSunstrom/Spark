#include "sub.hpp"

namespace ac
{
	__A_CORE_API__ void publish_to_topic(subscription_topic topic, std::any value)
	{
		if (topic == subscription_topic::EVERY_EVENT)
			for (auto& sub : subscriptions)
			{
				sub->publish(topic, value);
				return;
			}

		for (auto& sub : subscriptions)
			if (sub->m_topic == topic)
				sub->publish(topic, value);
	}
}