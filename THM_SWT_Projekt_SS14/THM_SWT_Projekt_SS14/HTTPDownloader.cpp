#include "HTTPDownloader.h"
#include <curl/curl.h>
#include <curl/easy.h>
#include <curl/curlbuild.h>
#include <sstream>
#include <iostream>

using namespace std;

/* spezifische write-Funktion:
 * Ausgabe von cURL in stringstream umleiten
 */
size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    string data((const char*) ptr, (size_t) size * nmemb);
    *((stringstream*) stream) << data << endl;
    return size * nmemb;
}

HTTPDownloader::HTTPDownloader() {
    curl = curl_easy_init();
}

HTTPDownloader::~HTTPDownloader() {
    curl_easy_cleanup(curl);
}

string HTTPDownloader::download(const std::string& url) {
	// Inhalt der URL in Variable out speichern
	std::stringstream out;

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1); 
	curl_easy_setopt(curl, CURLOPT_TRANSFER_ENCODING, "deflate");
	// spezifische write-Funktion übergeben
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
	// Datei von URL herunterladen
	CURLcode res = curl_easy_perform(curl);
	if (res != CURLE_OK) {
		// Fehlermeldung ausgeben
		fprintf(stderr, "curl_easy_perform() konnte nicht korrekt ausgeführt werden: %s\n",
			curl_easy_strerror(res));
	}
	return out.str();
}