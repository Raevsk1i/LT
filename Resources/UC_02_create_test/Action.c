Action()
{
	int number;
	lr_param_sprintf("projectName", "%s%s%s%s%s",
	                 lr_eval_string("{p_RandomLetter}"),
	                 lr_eval_string("{p_RandomLetter}"),
	                 lr_eval_string("{p_RandomLetter}"),
	                 lr_eval_string("{p_RandomLetter}"),
	                 lr_eval_string("{p_RandomLetter}"));
	
	number = rand()%5 + 1;
	lr_save_int(number, "numberOfUsers");
	               
	              
	web_set_sockets_option("SSL_VERSION", "AUTO");
	
	web_set_max_html_param_len("16384");

	web_set_sockets_option("TLS_SNI", "0");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Not/A)Brand\";v=\"8\", \"Chromium\";v=\"126\", \"Microsoft Edge\";v=\"126\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("dev-boomq.pflb.ru", 
		"URL=https://dev-boomq.pflb.ru/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/static/media/loading.b59fa25397e07d75b9ac55ace151e625.svg", "Referer=https://dev-boomq.pflb.ru/authorize", ENDITEM, 
		"Url=/static/media/logo.f5ae2890e77693e018920d4ad41c643c.svg", "Referer=https://dev-boomq.pflb.ru/authorize", ENDITEM, 
		"Url=/static/media/Montserrat-SemiBold.197213592de7a2a62e06.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Bold.180ba33d8de7dcfe80a0.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Medium.d42dad28f6470e5162c2.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Regular.3db65dc4b858f0fed4fb.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		LAST);

	lr_start_transaction("UC_02_TR_01_login");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	
	web_reg_save_param_ex(
		"ParamName=authToken",
		"LB=",
		"RB=\n",
		SEARCH_FILTERS,
		"Scope=HEADERS",
		"HeaderNames=Authorization",
		LAST);

	web_submit_data("login", 
		"Action=https://dev-boomq.pflb.ru/auth-srv/login", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"Referer=https://dev-boomq.pflb.ru/authorize", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=user_2@mail.ru", ENDITEM, 
		"Name=password", "Value=Wsx321!@#", ENDITEM, 
		"Name=submit", "Value=Login", ENDITEM, 
		LAST);
	
	web_add_auto_header("Authorization",
		"Bearer {authToken} ");

	

	web_url("config.json", 
		"URL=https://dev-boomq.pflb.ru/config.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_url("modelSchema", 
		"URL=https://dev-boomq.pflb.ru/project-srv/modelSchema", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_url("user", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../static/media/en.b1acfc6b06bfe6e29bfbfc06d09d8177.svg", "Referer=https://dev-boomq.pflb.ru/account/new-test", ENDITEM, 
		LAST);

	web_url("identityProvider", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/identityProvider", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_url("team", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	
	web_reg_save_param_ex(
		"ParamName=authToken",
		"LB=",
		"RB=\n",
		SEARCH_FILTERS,
		"Scope=HEADERS",
		"HeaderNames=Authorization",
		LAST);

	web_url("teamContext", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=11", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	
	web_add_auto_header("Authorization",
		"Bearer {authToken} ");


	web_url("testRunner", 
		"URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_02_TR_01_login",LR_AUTO);

	lr_think_time(15);

	lr_start_transaction("UC_02_TR_02_create_test");

	web_url("label", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/label?query=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	web_url("project", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project?sort=lastModified,desc&page=0&size=9", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_custom_request("project_2", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"comment\":\"\",\"contentFormat\":\"yaml\",\"contentModelVersion\":\"2.0.0\",\"labelSet\":[],\"requestCount\":1,\"testType\":\"STABLE\",\"projectName\":\"{projectName}\",\"contentV2\":{\"boomqTestPlan\":{\"threadGroups\":[{\"boomqConfiguration\":{\"resourceConfiguration\":{},\"loadProfilePercent\":100},\"enabled\":true,\"id\":\"5d2ae684-bb00-4497-8659-dfc24dc9b5b6\",\"label\":\"{label}\",\"steps\":[],\"type\":\"BOOMQ_STABLE_SCALABILITY\",\"typeDisplayName\":\"\",\"threadGroupElements\":["
		"{\"children\":[{\"children\":\"\",\"individualProperties\":{\"useKeepAlive\":true,\"type\":\"HTTP\",\"retrieveAllEmbeddedResources\":true,\"followRedirects\":true,\"automaticallyRedirect\":false,\"method\":\"POST\",\"browserCompatibleHeaders\":false,\"doMultipartPost\":false,\"path\":\"/api/messages/send/kafka-topic-group-1\",\"port\":\"48999\",\"protocol\":\"http\",\"search\":\"?\",\"serverName\":\"77.50.236.215\",\"headers\":{\"Content-Type\":\"application/json\"},\"queryParameters\":[],\"body\""
		":\"{\\n\\t\\\"rqUID\\\": \\\"{rqUID}\\\",\\n\\t\\\"clientId\\\": \\\"{clientId}\\\",\\n\\t\\\"openDate\\\": \\\"{openDate}\\\",\\n\\t\\\"closeDate\\\": \\\"{closeDate}\\\"\\n}\",\"bodyParameters\":[]},\"timerList\":[],\"label\":\"http://77.50.236.215:48999/api/messages/send/kafka-topic-group-1\",\"id\":\"7c48efa1-6d2a-414b-82a8-45049f119d8a\",\"type\":\"SAMPLER\",\"enabled\":true,\"assertions\":[],\"extractors\":[],\"typeDisplayName\":\"HTTP Request\"}],\"individualProperties\":{\""
		"includeDurationOfAllElementsToGeneratedSampler\":false,\"generateParentSampler\":false,\"type\":\"TRANSACTION\"},\"timerList\":[],\"label\":\"Transaction 1\",\"id\":\"efcff025-a99a-4587-8c69-4447767e5717\",\"type\":\"CONTROLLER\",\"enabled\":true,\"creationIndex\":1,\"typeDisplayName\":\"Transaction Controller\"}]}],\"runThreadGroupConsecutively\":false,\"loadProfileType\":\"PER_TEST\",\"functionalMode\":false,\"runTearDownAfterShutdown\":true,\"configurationElements\":[{\""
		"clearControlledByThreadGroup\":false,\"cookiePolicy\":\"STANDARD\",\"clearEachIteration\":false,\"userDefinedCookies\":[],\"label\":\"Http cookie manager\",\"id\":\"abe1e682-bcee-41fc-bc99-77ef8f9e5552\",\"type\":\"HTTP_COOKIE_MANAGER\",\"enabled\":true},{\"headers\":{\"User-Agent\":\"Mozilla/5.0\"},\"label\":\"Http header manager\",\"id\":\"b1a41990-aa14-4079-938d-250e31d7f212\",\"type\":\"HTTP_HEADER_MANAGER\",\"enabled\":true},{\"label\":\"Http request defaults\",\"type\":\""
		"HTTP_REQUEST_DEFAULTS\",\"enabled\":true,\"id\":\"df1eb733-d38f-4b43-a02e-52a883559c2a\",\"connectTimeout\":60000,\"responseTimeout\":120000}],\"loadProfile\":{\"usersPerStep\":{numberOfUsers},\"rampDownMs\":{rampDownMs},\"durationAddedOnLastStepMs\":0,\"boomqProfileType\":\"STABLE\",\"rampUpMs\":{rampUpMs},\"stepLengthMs\":{durationTestMs},\"stepCount\":1},\"timers\":[{\"timerType\":\"CONSTANT\",\"label\":\"boomq_timer_f01033db-f725-4194-a856-14c096144294\",\"id\":\"f01033db-f725-4194-a856-14c096144294\",\"durationMs\":8000,\""
		"enabled\":true}]},\"slaGroupList\":[],\"supportingFiles\":[],\"supportingFilesV2\":[]},\"totalDuration\":{totalDurationMin}}", 
		EXTRARES,
		"Url=../static/media/check.9725c0396328bae9471b624111fc14ca.svg", "Referer=https://dev-boomq.pflb.ru/account/new-test", ENDITEM, 
		LAST);

	lr_end_transaction("UC_02_TR_02_create_test",LR_AUTO);

	lr_start_transaction("UC_02_TR_03_logout");

	lr_end_transaction("UC_02_TR_03_logout",LR_AUTO);

	return 0;
}