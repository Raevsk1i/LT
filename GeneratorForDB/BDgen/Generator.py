import psycopg2
import datetime
from faker import Faker
from psycopg2 import sql

conn = psycopg2.connect(dbname='postgresql', user='admin',
                        password='admin', host='192.168.175.128')
cursor = conn.cursor()
fake = Faker('ru_RU')

start_date = datetime.datetime(2024, 0o6, 14)
end_date = datetime.datetime(2024, 0o6, 17)
start_pass = '{bcrypt}$2a$10$'
count = 1894
fls = 'false'

values = []

while count != 50001:
    conn.autocommit = True
    count += 1
    email = fake.email()
    passw = start_pass + fake.password(length=53)
    lang = fake.random_elements(["EN", "RU"], 1)
    date = fake.date_time_between(start_date, end_date)
    flag = fake.random_elements(["true", "false"], 1)
    boomqUser = (str(count), email, passw, lang[0], fls, str(date), flag[0], '')
    values.append(boomqUser)
    if len(values) == 100 or count == 50000:
        insert = sql.SQL(
            'INSERT INTO boomq_user (user_id, email, password, language, enable_notification, create_date, enabled, '
            'display_name) VALUES {}').format(
            sql.SQL(',').join(map(sql.Literal, values)))
        cursor.execute(insert)
        values = []
