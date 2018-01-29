FROM php:5.6-apache

WORKDIR /boston.gov
ENV APACHE_DOCUMENT_ROOT /boston.gov/docroot
RUN sed -ri -e 's!/var/www/html!${APACHE_DOCUMENT_ROOT}!g' /etc/apache2/sites-available/*.conf && \
    sed -ri -e 's!/var/www/!${APACHE_DOCUMENT_ROOT}!g' /etc/apache2/apache2.conf /etc/apache2/conf-available/*.conf && \
    a2enmod rewrite

RUN curl -sL https://deb.nodesource.com/setup_8.x | bash -
RUN apt-get update && \
    apt-get install -y --no-install-recommends git zip unzip bzip2 libbz2-dev rsync nodejs libgd-dev mysql-client && \
    docker-php-ext-install pdo_mysql gd bz2
RUN curl --silent --show-error https://getcomposer.org/installer | php
RUN mv composer.phar /usr/local/bin/composer 

ADD docker/php.ini /usr/local/etc/php/

ADD package.json package-lock.json /boston.gov/
RUN npm install

ADD composer.json composer.lock /boston.gov/
RUN composer install
RUN ln -s /boston.gov/vendor/bin/drush /usr/local/bin/drush

ADD . /boston.gov
RUN ./task.sh setup:build:make
