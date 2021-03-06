/* Icinga 2 | (c) 2012 Icinga GmbH | GPLv2+ */

#ifndef HTTPUTILITY_H
#define HTTPUTILITY_H

#include "remote/httprequest.hpp"
#include "remote/httpresponse.hpp"
#include "base/dictionary.hpp"

namespace icinga
{

/**
 * Helper functions.
 *
 * @ingroup remote
 */
class HttpUtility
{

public:
	static Dictionary::Ptr FetchRequestParameters(HttpRequest& request);
	static void SendJsonBody(HttpResponse& response, const Dictionary::Ptr& params, const Value& val);
	static Value GetLastParameter(const Dictionary::Ptr& params, const String& key);
	static void SendJsonError(HttpResponse& response, const Dictionary::Ptr& params, const int code,
		const String& verbose = String(), const String& diagnosticInformation = String());

private:
	static String GetErrorNameByCode(int code);

};

}

#endif /* HTTPUTILITY_H */
