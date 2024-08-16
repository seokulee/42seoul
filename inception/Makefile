DOCKER_COMPOSE			:= srcs/docker-compose.yml

CERTIFICATE				:= srcs/requirements/certificate
CERTIFICATE_MAKEFILE	:= srcs/requirements/tools/certificate
export CERTIFICATE

DATA_FOLDER				:= data
VOLUME_FOLDER			:= volumes
VOLUME					:= $(HOME)/$(DATA_FOLDER)/$(VOLUME_FOLDER)
MARIADB_VOLUME			:= $(VOLUME)/mariadb
WORDPRESS_VOLUME		:= $(VOLUME)/wordpress
export VOLUME

export DOMAIN

NAME					:= .inception

all: $(NAME)

$(NAME): set_certificate set_hosts
	@mkdir -p $(MARIADB_VOLUME) $(WORDPRESS_VOLUME)
	docker compose -f $(DOCKER_COMPOSE) up --build -d

clean:
	docker compose -f $(DOCKER_COMPOSE) down --rmi all --volumes --remove-orphans
	make -C $(CERTIFICATE_MAKEFILE) clean

fclean:
	make clean
	docker system prune --all --volumes --force
	@make -C $(CERTIFICATE_MAKEFILE) fclean
	sudo rm -rf $(VOLUME)
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re

set_hosts: $(HOSTFILE_SETUP)

$(HOSTFILE_SETUP):
	$(info Setting up /etc/hosts file to access $(DOMAIN_NAME)...)
	@if [ ! -f $(HOSTFILE_SETUP) ]; then \
		sudo chmod 777 /etc/hosts; \
		sudo echo "127.0.0.1 $(DOMAIN_NAME)" >> /etc/hosts; \
		touch $@; \
	fi
	@echo "Setting up /etc/hosts file to access $(DOMAIN_NAME)...Done."

set_certificate:
	@if [ ! -d $(CERTIFICATE) ]; then \
		mkdir $(CERTIFICATE); \
	fi
	$(eval DOMAIN := $(shell grep '^DOMAIN=' srcs/.env | cut -d '=' -f 2))
	$(info Checking certificate for $(DOMAIN))
	@echo "Setting up certificate for $(DOMAIN)"
	make -C $(CERTIFICATE_MAKEFILE) all
	@echo "Successfully set up certificate for $(DOMAIN)"
	@echo "Checking certificate for $(DOMAIN) Done"

.PHONY: set_certificate

status: ps images volume network top

.PHONY: status

ps logs images top:
	docker compose -f $(DOCKER_COMPOSE) $@

.PHONY: ps logs images top

network volume:
	docker $@ ls

.PHONY: network volume
