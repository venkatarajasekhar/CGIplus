/*
  CGIplus Copyright (C) 2012 Rafael Dantas Justo

  This file is part of CGIplus.

  CGIplus is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  CGIplus is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with CGIplus.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim.hpp>

#include <cgiplus/MediaType.hpp>

CGIPLUS_NS_BEGIN

MediaType::Value MediaType::detect(const string &value)
{
	string mediaType = boost::algorithm::to_lower_copy(value);
	boost::trim(mediaType);

	if (mediaType == "*/*") {
		return ANY;

	} else if (mediaType == "application/*") {
		return APPLICATION_ANY;

	} else if (mediaType == "application/json") {
		return APPLICATION_JSON;

	} else if (mediaType == "application/xml") {
		return APPLICATION_XML;

	} else if (mediaType == "application/x-www-form-urlencoded") {
		return APPLICATION_X_WWW_FORM_URL_ENCODED;

	} else if (mediaType == "multipart/*") {
		return MULTIPART_ANY;

	} else if (mediaType == "multipart/form-data") {
		return MULTIPART_FORM_DATA;

	} else if (mediaType == "text/*") {
		return TEXT_ANY;

	} else if (mediaType == "text/html") {
		return TEXT_HTML;

	} else if (mediaType == "text/plain") {
		return TEXT_PLAIN;

	} else if (mediaType == "text/xml") {
		return TEXT_XML;

	} else {
		return UNKNOWN;
	}
}

string MediaType::toString(const Value value)
{
	switch(value) {
	case UNDEFINED:
		break;
	case ANY:
		return "*/*";
	case APPLICATION_ANY:
		return "application/*";
	case APPLICATION_JSON:
		return "application/json";
	case APPLICATION_XML:
		return "application/xml";
	case APPLICATION_X_WWW_FORM_URL_ENCODED:
		return "application/x-www-form-urlencoded";
	case MULTIPART_ANY:
		return "multipart/*";
	case MULTIPART_FORM_DATA:
		return "multipart/form-data";
	case TEXT_ANY:
		return "text/*";
	case TEXT_HTML:
		return "text/html";
	case TEXT_PLAIN:
		return "text/plain";
	case TEXT_XML:
		return "text/xml";
	case UNKNOWN:
		break;
	}

	return "";
}

CGIPLUS_NS_END
